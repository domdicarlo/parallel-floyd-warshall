#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <semaphore.h> 
#include <pthread.h>

// Worker args struct for Parallel Worker thread
struct worker_args
{
    unsigned int starting_row; // The first row to compute on for a thread
    unsigned int ending_row; // The last row to compute on for a thread
    unsigned int vertex_count; // How many vertices are in the graph (size of matrix)
    unsigned int *dist_matrix; // Pointer to dist_matrix to compute upon
    unsigned int thread_count; // How many threads are working in parallel
    sem_t *sem_matrix; // Matrix of semaphores to sync threads
};
typedef struct worker_args worker_args_t;


/* floyd_warshall_serial
 * Description: Implementation of the Floyd Warshall's Shortest Path
 *              algorithm to find the smallest distance between every
 *              pair of vertices in a graph
 * Input: unsigned int *matrix - A pointer to a 2-D array in row major ordering
 *                               for unsigned ints. Holds the original 
 *                               adjacency matrix graph representation
 *        unsigned int vertex_count - the number of vertices in the graph
 * 
 * Output: 0 on success. Modifies the graph in place to hold
 *         the shortest distances
 */ 
int floyd_warshall_serial(unsigned int *matrix, unsigned int vertex_count)
{
    for (int k = 0; k < vertex_count; k++)
    {
        for (int i = 0; i < vertex_count; i++)
        {
            for (int j = 0; j < vertex_count; j++)
            {
                // if we have an infinite value, we definitely won't 
                // get a new minimum this round
                if (*(matrix + (i * vertex_count) + k) == __UINT32_MAX__ ||
                    *(matrix + (k * vertex_count) + j) == __UINT32_MAX__)
                {
                    continue;
                }

                if (*(matrix + (i * vertex_count) + j) >
                        (*(matrix + (i * vertex_count) + k) +
                         *(matrix + (k * vertex_count) + j)))
                {
                    *(matrix + (i * vertex_count) + j) = 
                        *(matrix + (i * vertex_count) + k) +
                        *(matrix + (k * vertex_count) + j);
                }
            }
        }
    }
    return 0;
}

/* floyd_warshall_fractional
 * Description: Helper function for floyd_warshall_parallel. Computes on a portion
 *              of the input adjacency matrix and finds the max distance values
 *              for that portion when working in parallel with other threads.
 * Input: unsigned int starting_row - the starting row to compute on
 *        unsigned int ending_row - the last row to compute on
 *        unsigned int* dist_matrix - adjacency matrix graph representation to build upon
 *        unsigned int thread_count - the number of threads working on
 *                                    the adjacency matrix. Needed for tracking
 *                                    how much to increment semaphores in implementation
 * 
 * Output: 0 on success. Modifies the graph in place to hold
 *         the shortest distances
 */ 
unsigned int floyd_warshall_fractional(unsigned int starting_row, 
                          unsigned int ending_row,
                          unsigned int vertex_count,
                          unsigned int *dist_matrix,
                          unsigned int thread_count,
                          sem_t *sem_matrix)
{
    for (int k = 0; k < vertex_count; k++)
    {
        // block until we know the k th row is good to go.
        sem_wait((sem_matrix + k));

        // Only execute for assigned rows
        for (int i = starting_row; i <= ending_row; i++)
        {
            for (int j = 0; j < vertex_count; j++)
            {
                // if we have an infinite value, we definitely won't 
                // get a new minimum this round
                if (*(dist_matrix + (i * vertex_count) + k) == __UINT32_MAX__ ||
                    *(dist_matrix + (k * vertex_count) + j) == __UINT32_MAX__)
                {
                    continue;
                }

                // this part is the same as before
                if (*(dist_matrix + (i * vertex_count) + j) >
                        (*(dist_matrix + (i * vertex_count) + k) +
                            *(dist_matrix + (k * vertex_count) + j)))
                {
                    *(dist_matrix + (i * vertex_count) + j) = 
                        *(dist_matrix + (i * vertex_count) + k) +
                        *(dist_matrix + (k * vertex_count) + j);
                }
            }
            // Every time we finish one of our own rows,
            // (when it is equal to k) 
            // we need to update the semaphore values
            if (k >= starting_row && k <= ending_row) 
            {
                for (int z = 0; z < thread_count; z++)
                {
                    // the + 1 is an offset, so that for iteration 0 we
                    // still check a semaphore (for simplicity of loop)
                    sem_post(sem_matrix + k + 1);
                }
            }
        }
    }
    
    return 0;
}

/* floyd_warshall_worker
 * Description: Helper function for floyd_warshall_parallel. Function each
 *              spawned thread executes.
 * Input: See worker_args struct at top of file.
 * 
 * Output: Nothing.
 */ 
void *floyd_warshall_worker(void *args)
{
    struct worker_args *wa = (struct worker_args *)args; 

    floyd_warshall_fractional(wa->starting_row, wa->ending_row, wa->vertex_count,
                          wa->dist_matrix, wa->thread_count, wa->sem_matrix);
    pthread_exit(NULL);
    return NULL;
}

/* floyd_warshall_parallel
 * Description: Parallel implementation of the Floyd Warshall's Shortest Path
 *              algorithm to find the smallest distance between every
 *              pair of vertices in a graph
 * Input: unsigned int *matrix - A pointer to a 2-D array in row major ordering
 *                               for unsigned ints. Holds the original 
 *                               adjacency matrix graph representation
 *        unsigned int vertex_count - the number of vertices in the graph
 *        unsigned int thread_count - the number of threads to employ in parallel
 * 
 * Output: 0 on success. Modifies the graph in place to hold
 *         the shortest distances
 */ 
int floyd_warshall_parallel(unsigned int *matrix, unsigned int vertex_count, 
                            unsigned int thread_count)
{
    // the + 1 is an offset, so that for iteration 0 we
    // still check a semaphore (for simplicity of loop)
    sem_t *sem_matrix =
                calloc(vertex_count + 1, sizeof(sem_t));
    // create a semaphore for each row (one for each k value)
    // make one extra one due to the nature of the loop
    sem_init(sem_matrix, 1, thread_count); // first semaphore should already be unlocked

    for (int i = 1; i <= vertex_count; i++)
    {
        // subsequent ones need to wait.
        sem_init(sem_matrix + i, 1, 0);
    }

    if (vertex_count < thread_count)
    {
        thread_count = vertex_count;
    }

    pthread_t *threads = calloc(thread_count, sizeof(pthread_t));

    unsigned int rows_per_thread = vertex_count / thread_count;
    unsigned int threads_with_extra_row = vertex_count % thread_count;
    unsigned int next_unassigned_row = 0;


    for (int i = 1; i < thread_count; i++)
    {
        worker_args_t *wa = calloc(1, sizeof(worker_args_t));
        wa->dist_matrix = matrix;
        wa->sem_matrix = sem_matrix;
        wa->vertex_count = vertex_count;
        wa->starting_row = next_unassigned_row;
        // subtract 1 so that if you only have 1 row per thread,
        // both start and end are the same number
        wa->ending_row = next_unassigned_row + rows_per_thread - 1;
        wa->thread_count = thread_count;
        // determine if we will have one extra row this thread
        if (i <= threads_with_extra_row) 
        {
            wa->ending_row++;
        }
        next_unassigned_row = wa->ending_row + 1;

        if (pthread_create(threads + i, NULL, floyd_warshall_worker, wa) != 0)
        {
            printf("floyd_warshall_parallel: error, could not"
                   " create a worker thread");
        }
        if (next_unassigned_row >= vertex_count)
        {
            break;
        }
    }

    // Execute this thread's portion of the work
    floyd_warshall_fractional(next_unassigned_row,
                        next_unassigned_row + rows_per_thread - 1, vertex_count, 
                            matrix, thread_count, sem_matrix);

    // Rejoin other threads
    for (int i = 0; i < thread_count; i++)
    {
        pthread_join(threads[i], NULL);
    }

    return 0;
}