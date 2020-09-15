#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "import.h"
#include "floyd_warshall.h"

// Program to run a parallelized Floyd Warshall shortest path algorithm on 
// an input adjacency matrix graph.

// See README.md for guide on how to run.

int main(int argc, char *argv[]) 
{ 
    if (argc == 3) 
    {
        char *output_file = "../main_parallel_out/output.txt";
        unsigned int num_threads = atoi(argv[2]);
        char *file_name = argv[1];

        unsigned int *dimension = calloc(1, sizeof(unsigned int));
        unsigned int *adj_matix = read_in_adjacency_matrix(file_name, dimension, false);

        floyd_warshall_parallel(adj_matix, *dimension, num_threads);

        FILE * output = fopen(output_file, "w+");

        fprintf(output, "%u\n", *dimension);

        for (int i = 0; i < *dimension; i++) 
        {
            for (int j = 0; j < *dimension; j++)
            {
                fprintf(output, "%u ", *(adj_matix + (i * *dimension) + j));
            }
            fprintf(output, "\n");
        }

        printf("\nSuccess. See ../main_parallel_out/output.txt for result\n\n");
        return 0; 
    }
    else
    {
        printf("\nError, invalid arguments. Please give exactly 2 arguments after"
               " the program name, the path to the input text file, followed "
               "by the number of threads."
               " See README.md for formatting guidelines for the text file.\n\n");
        return 1;
    }
} 
