#ifndef FLOYD_WARSHALL_H
#define FLOYD_WARSHALL_H

#include <semaphore.h> 

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
int floyd_warshall_serial(unsigned int *matrix, unsigned int vertex_count);

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
                            unsigned int thread_count);

#endif