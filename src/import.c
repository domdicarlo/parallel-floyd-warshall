#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "import.h"

/* read_in_adjacency_matrix
 * Description: Takes in a string path to a file containing the
 *              formatted adjacency matrix and outputs a pointer to 
 *              newly malloc'd adjacency matrix. The adjacency matrix
 *              text file should be formatted in the same manner 
 *              described in the README.
 * Input: char * file_path - a string path tothe file
 *        unsigned int *dimension - a pointer to an int to fill in with
 *                                  the input graph's dimension (vertex_count)
 * 
 * Output: usigned int * - a pointer to an adjacency matrix on success.
 *         NULL otherwise for an invalid input graph.
 */ 
unsigned int *read_in_adjacency_matrix(char *file_path, 
                                        unsigned int *dimension,
                                        bool computed)
{
    FILE *fp = fopen(file_path, "r");

    unsigned int vertex_count;

    if (fscanf(fp, "%u\n", &vertex_count) != 1)
    {
        printf("read_in_adjacency_matrix: ERROR."
               " Misformatted input file. Vertex count on first line.\n\n");
        return NULL;
    }

    *dimension = vertex_count;
    unsigned int *input_matrix = 
                    calloc(vertex_count * vertex_count, sizeof(unsigned int));

    for(int i = 0; i < vertex_count; i++)
    {
        for (int j = 0; j < vertex_count; j++)
        {
            // Look for unsigned int
            if (fscanf(fp, "%u ", input_matrix + (i * vertex_count) + j) != 1)
            {
                // If an unsigned int wasn't there, look for I char
                if (fscanf(fp, "I ") != 0)
                {
                    // No I or unsigned int... Something bad.
                    printf("read_in_adjacency_matrix: ERROR."
                        " Misformatted input file. Not I or a uint.\n\n");
                    return NULL;
                }
                else
                {
                    // printf("here is triggered for i: %u j: %u\n", i, j);
                    *(input_matrix + (i * vertex_count) + j) = __UINT32_MAX__;
                }
                
            }
            else if (*(input_matrix + (i * vertex_count) + j) > 1000 
                     && !computed)
            {
                    // Edge weight greater than 1000 detected.
                    // printf("here is triggered for i: %u j: %u\n", i, j);
                    printf("edge weight: %u\n", *(input_matrix + (i * vertex_count) + j));
                    printf("read_in_adjacency_matrix: ERROR."
                        " Misformatted input file. Edge > 1000.\n\n");
                    return NULL;
            }

            // check that diagonals are always equal to 0
            if (i == j && *(input_matrix + (i * vertex_count) + j) != 0)
            {
                printf("read_in_adjacency_matrix: ERROR."
                    " Misformatted input file. Diagonals not equal to 0.\n\n");
                return NULL;
            }
        }
        if (fscanf(fp, "\n") != 0)
        {
            printf("read_in_adjacency_matrix: ERROR."
                " Misformatted input file. Doesn't end in newline.\n\n");
            return NULL;
        };
    }


    return input_matrix;
}