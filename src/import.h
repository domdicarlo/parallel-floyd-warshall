#ifndef IMPORT_H
#define IMPORT_H

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
                                       bool computed);

#endif