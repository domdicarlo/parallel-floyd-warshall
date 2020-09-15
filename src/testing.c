#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <semaphore.h> 
#include "stopwatch.h"
#include "import.h"
#include "floyd_warshall.h"

// Testing Script for HW1

// Global Variables for File Names
char *test_file_name2 = "../tests/floyd_warshall/mass_testing/"
                        "test_cases/vertex_count_2";
char *test_file_name4 = "../tests/floyd_warshall/mass_testing/"
                        "test_cases/vertex_count_4";
char *test_file_name8 = "../tests/floyd_warshall/mass_testing/"
                        "test_cases/vertex_count_8";
char *test_file_name16 = "../tests/floyd_warshall/mass_testing/"
                        "test_cases/vertex_count_16";
char *test_file_name32 = "../tests/floyd_warshall/mass_testing/"
                        "test_cases/vertex_count_32";
char *test_file_name64 = "../tests/floyd_warshall/mass_testing/"
                        "test_cases/vertex_count_64";
char *test_file_name128 = "../tests/floyd_warshall/mass_testing/"
                        "test_cases/vertex_count_128";
char *test_file_name256 = "../tests/floyd_warshall/mass_testing/"
                        "test_cases/vertex_count_256";
char *test_file_name512 = "../tests/floyd_warshall/mass_testing/"
                        "test_cases/vertex_count_512";
char *test_file_name1024 = "../tests/floyd_warshall/mass_testing/"
                        "test_cases/vertex_count_1024";
char *result_file_name2 = "../tests/floyd_warshall/mass_testing/"
                        "expected_results/vertex_count_2";
char *result_file_name4 = "../tests/floyd_warshall/mass_testing/"
                        "expected_results/vertex_count_4";
char *result_file_name8 = "../tests/floyd_warshall/mass_testing/"
                        "expected_results/vertex_count_8";
char *result_file_name16 = "../tests/floyd_warshall/mass_testing/"
                        "expected_results/vertex_count_16";
char *result_file_name32 = "../tests/floyd_warshall/mass_testing/"
                        "expected_results/vertex_count_32";
char *result_file_name64 = "../tests/floyd_warshall/mass_testing/"
                        "expected_results/vertex_count_64";
char *result_file_name128 = "../tests/floyd_warshall/mass_testing/"
                        "expected_results/vertex_count_128";
char *result_file_name256 = "../tests/floyd_warshall/mass_testing/"
                        "expected_results/vertex_count_256";
char *result_file_name512 = "../tests/floyd_warshall/mass_testing/"
                        "expected_results/vertex_count_512";
char *result_file_name1024 = "../tests/floyd_warshall/mass_testing/"
                        "expected_results/vertex_count_1024";


bool compare_matrices(unsigned int *mat1, unsigned int *mat2, unsigned int dim)
{
    for (int i = 0; i < dim; i++)
    {
        for (int j = 0; j < dim; j++)
        {
            if (*(mat1 + (i * dim) + j) !=
                *(mat2 + (i * dim) + j))
            {
                // printf("failure at i: %u j: %u\n", i,j);
                // printf("Here is the first val %u\n", 
                // *(mat1 + (i * dim) + j));
                // printf("Here is the second val %u\n",
                // *(mat2 + (i * dim) + j));
                return false;
            }
        }
    }
    return true;
}


void run_n_experiments_parallel(char *file_path, int t)
{
    StopWatch_t *timer = calloc(1, sizeof(StopWatch_t));
    unsigned int *vertex_count = calloc(1, sizeof(unsigned int));

    printf("Parallel:\n\n");
    FILE * fp_parallel_1 = fopen(file_path, "w+");

//    test 
    unsigned int *adj_matrix_1 = 
        read_in_adjacency_matrix(test_file_name2, vertex_count, false);
    startTimer(timer); 
    floyd_warshall_parallel(adj_matrix_1, *vertex_count, t);
    stopTimer(timer); 
    printf("N = 2 Elapsed time: %fp\n\n", getElapsedTime(timer));
    fprintf(fp_parallel_1, "%f ", getElapsedTime(timer));

    // test
    adj_matrix_1 = 
        read_in_adjacency_matrix(test_file_name4, vertex_count, false);
    startTimer(timer); 
    floyd_warshall_parallel(adj_matrix_1, *vertex_count, t);
    stopTimer(timer); 
    printf("N = 4 Elapsed time: %fp\n\n", getElapsedTime(timer));
    fprintf(fp_parallel_1, "%f ", getElapsedTime(timer));

    // test
    adj_matrix_1 = 
        read_in_adjacency_matrix(test_file_name8, vertex_count, false);
    startTimer(timer); 
    floyd_warshall_parallel(adj_matrix_1, *vertex_count, t);
    stopTimer(timer); 
    printf("N = 8 Elapsed time: %fp\n\n", getElapsedTime(timer));
    fprintf(fp_parallel_1, "%f ", getElapsedTime(timer));

    // test
    adj_matrix_1 = 
        read_in_adjacency_matrix(test_file_name16, vertex_count, false);
    startTimer(timer); 
    floyd_warshall_parallel(adj_matrix_1, *vertex_count, t);
    stopTimer(timer); 
    printf("N = 16 Elapsed time: %fp\n\n", getElapsedTime(timer));
    fprintf(fp_parallel_1, "%f ", getElapsedTime(timer));

    // test
    adj_matrix_1 = 
        read_in_adjacency_matrix(test_file_name32, vertex_count, false);
    startTimer(timer); 
    floyd_warshall_parallel(adj_matrix_1, *vertex_count, t);
    stopTimer(timer); 
    printf("N = t Elapsed time: %fp\n\n", getElapsedTime(timer));
    fprintf(fp_parallel_1, "%f ", getElapsedTime(timer));

    // test
    adj_matrix_1 = 
        read_in_adjacency_matrix(test_file_name64, vertex_count, false);
    startTimer(timer); 
    floyd_warshall_parallel(adj_matrix_1, *vertex_count, t);
    stopTimer(timer); 
    printf("N = 64 Elapsed time: %fp\n\n", getElapsedTime(timer));
    fprintf(fp_parallel_1, "%f ", getElapsedTime(timer));

    // test
    adj_matrix_1 = 
        read_in_adjacency_matrix(test_file_name128, vertex_count, false);
    startTimer(timer); 
    floyd_warshall_parallel(adj_matrix_1, *vertex_count, t);
    stopTimer(timer); 
    printf("N = 128 Elapsed time: %fp\n\n", getElapsedTime(timer));
    fprintf(fp_parallel_1, "%f ", getElapsedTime(timer));

    // test
    adj_matrix_1 = 
        read_in_adjacency_matrix(test_file_name256, vertex_count, false);
    startTimer(timer); 
    floyd_warshall_parallel(adj_matrix_1, *vertex_count, t);
    stopTimer(timer); 
    printf("N = 256 Elapsed time: %fp\n\n", getElapsedTime(timer));
    fprintf(fp_parallel_1, "%f ", getElapsedTime(timer));

    // test
    adj_matrix_1 = 
        read_in_adjacency_matrix(test_file_name512, vertex_count, false);
    startTimer(timer); 
    floyd_warshall_parallel(adj_matrix_1, *vertex_count, t);
    stopTimer(timer); 
    printf("N = 512 Elapsed time: %fp\n\n", getElapsedTime(timer));
    fprintf(fp_parallel_1, "%f ", getElapsedTime(timer));

    // test
    adj_matrix_1 = 
        read_in_adjacency_matrix(test_file_name1024, vertex_count, false);
    startTimer(timer); 
    floyd_warshall_parallel(adj_matrix_1, *vertex_count, t);
    stopTimer(timer); 
    printf("N = 1024 Elapsed time: %fp\n\n", getElapsedTime(timer));
    fprintf(fp_parallel_1, "%f ", getElapsedTime(timer));

}
void run_n_experiments_serial(char *file_path)
{
    printf("Serial:\n\n");
    StopWatch_t *timer = calloc(1, sizeof(StopWatch_t));
    unsigned int *vertex_count = calloc(1, sizeof(unsigned int));

    FILE * fp_serial_1 = fopen(file_path, "w");

    unsigned int *adj_matrix_1 = 
        read_in_adjacency_matrix(test_file_name2, vertex_count, false);
    startTimer(timer); 
    floyd_warshall_serial(adj_matrix_1, *vertex_count);
    stopTimer(timer); 
    printf("N = 2 Elapsed time: %fp\n\n", getElapsedTime(timer));
    fprintf(fp_serial_1, "%f ", getElapsedTime(timer));

    // test
    adj_matrix_1 = 
        read_in_adjacency_matrix(test_file_name4, vertex_count, false);
    startTimer(timer); 
    floyd_warshall_serial(adj_matrix_1, *vertex_count);
    stopTimer(timer); 
    printf("N = 4 Elapsed time: %fp\n\n", getElapsedTime(timer));
    fprintf(fp_serial_1, "%f ", getElapsedTime(timer));

    // test
    adj_matrix_1 = 
        read_in_adjacency_matrix(test_file_name8, vertex_count, false);
    startTimer(timer); 
    floyd_warshall_serial(adj_matrix_1, *vertex_count);
    stopTimer(timer); 
    printf("N = 8 Elapsed time: %fp\n\n", getElapsedTime(timer));
    fprintf(fp_serial_1, "%f ", getElapsedTime(timer));

    // test
    adj_matrix_1 = 
        read_in_adjacency_matrix(test_file_name16, vertex_count, false);
    startTimer(timer); 
    floyd_warshall_serial(adj_matrix_1, *vertex_count);
    stopTimer(timer); 
    printf("N = 16 Elapsed time: %fp\n\n", getElapsedTime(timer));
    fprintf(fp_serial_1, "%f ", getElapsedTime(timer));

    // test
    adj_matrix_1 = 
        read_in_adjacency_matrix(test_file_name32, vertex_count, false);
    startTimer(timer); 
    floyd_warshall_serial(adj_matrix_1, *vertex_count);
    stopTimer(timer); 
    printf("N = 32 Elapsed time: %fp\n\n", getElapsedTime(timer));
    fprintf(fp_serial_1, "%f ", getElapsedTime(timer));

    // test
    adj_matrix_1 = 
        read_in_adjacency_matrix(test_file_name64, vertex_count, false);
    startTimer(timer); 
    floyd_warshall_serial(adj_matrix_1, *vertex_count);
    stopTimer(timer); 
    printf("N = 64 Elapsed time: %fp\n\n", getElapsedTime(timer));
    fprintf(fp_serial_1, "%f ", getElapsedTime(timer));

    // test
    adj_matrix_1 = 
        read_in_adjacency_matrix(test_file_name128, vertex_count, false);
    startTimer(timer); 
    floyd_warshall_serial(adj_matrix_1, *vertex_count);
    stopTimer(timer); 
    printf("N = 128 Elapsed time: %fp\n\n", getElapsedTime(timer));
    fprintf(fp_serial_1, "%f ", getElapsedTime(timer));

    // test
    adj_matrix_1 = 
        read_in_adjacency_matrix(test_file_name256, vertex_count, false);
    startTimer(timer); 
    floyd_warshall_serial(adj_matrix_1, *vertex_count);
    stopTimer(timer); 
    printf("N = 256 Elapsed time: %fp\n\n", getElapsedTime(timer));
    fprintf(fp_serial_1, "%f ", getElapsedTime(timer));

    // test
    adj_matrix_1 = 
        read_in_adjacency_matrix(test_file_name512, vertex_count, false);
    startTimer(timer); 
    floyd_warshall_serial(adj_matrix_1, *vertex_count);
    stopTimer(timer); 
    printf("N = 512 Elapsed time: %fp\n\n", getElapsedTime(timer));
    fprintf(fp_serial_1, "%f ", getElapsedTime(timer));

    // test
    adj_matrix_1 = 
        read_in_adjacency_matrix(test_file_name1024, vertex_count, false);
    startTimer(timer); 
    floyd_warshall_serial(adj_matrix_1, *vertex_count);
    stopTimer(timer); 
    printf("N = 1024 Elapsed time: %fp\n\n", getElapsedTime(timer));
    fprintf(fp_serial_1, "%f ", getElapsedTime(timer));

}

int main()
{
    printf("-------------------------\n");
    printf("BEGIN TESTING\n");
    printf("-------------------------\n\n");
    bool success;

    // Testing for read_in_adjacency_matrix
    printf("-------------------------\n\n");
    printf("read_in_adjacency_matrix START TESTING\n\n");

    // create some arbitrary looking matrices for simple read-in test

    // test simple 4x4
    unsigned int *comp_matrix = calloc(16, sizeof(unsigned int));
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (j == i)
            {
                *(comp_matrix + (i * 4) + j) = 0;
            }
            else
            {
                *(comp_matrix + (i * 4) + j) = j + 1;
            }
        }
    }
    // test 11x11 for some double digit ints
    unsigned int *comp_matrix2 = calloc(121, sizeof(unsigned int));
    for (int i = 0; i < 11; i++)
    {
        for (int j = 0; j < 11; j++)
        {
            if (j == i)
            {
                *(comp_matrix2 + (i * 11) + j) = 0;
            }
            else if (j == 0)
            {
                *(comp_matrix2 + (i * 11)) = 0;
            }
            else
            {
                *(comp_matrix2 + (i * 11) + j) = j;
            }
        }
    }
    // test 6x6 with Infinity char
    unsigned int *comp_matrix3 = calloc(36, sizeof(unsigned int));
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            if (j == i)
            {
                *(comp_matrix3 + (i * 6) + j) = 0;
            }
            else if (j == 0)
            {
                *(comp_matrix3 + (i * 6)) = __UINT32_MAX__;
            }
            else
            {
                *(comp_matrix3 + (i * 6) + j) = j;
            }
        }
    }

    unsigned int *vertex_count = calloc(1, sizeof(unsigned int));
    unsigned int *input_matrix = 
    read_in_adjacency_matrix("../tests/read_in_adjacency_matrix/good_format.txt",
                             vertex_count, false);
    success = compare_matrices(input_matrix, comp_matrix, 4);
    if (success)
    {
        printf("Good format test - Simple all positive ints 4x4: PASSED\n\n");
    }
    else
    {
        printf("Good format test: FAILED\n\n");
    }
    input_matrix = 
    read_in_adjacency_matrix("../tests/read_in_adjacency_matrix/good_format2.txt",
                             vertex_count, false);
    success = compare_matrices(input_matrix, comp_matrix2, 11);
    if (success)
    {
        printf("Good format test 2 - Simple all positive ints 10x10: PASSED\n\n");
    }
    else
    {
        printf("Good format test 2: FAILED\n\n");
    }
    input_matrix = 
    read_in_adjacency_matrix("../tests/read_in_adjacency_matrix/good_format3.txt",
                             vertex_count, false);
    success = compare_matrices(input_matrix, comp_matrix3, 6);
    if (success)
    {
        printf("Good format test 3 - Reading in Infinity char: PASSED\n\n");
    }
    else
    {
        printf("Good format test 3: FAILED\n\n");
    }

    // testing that bad input data is rejected:
    unsigned int *result = 
    read_in_adjacency_matrix("../tests/read_in_adjacency_matrix/bad_format1.txt",
                             vertex_count, false);
    if (result == NULL)
    {
        printf("Bad format test 1 - Reject improper vertex count char: PASSED\n\n");
    }
    else
    {
        printf("Bad format test 1: FAILED\n\n");
    }
    result = 
    read_in_adjacency_matrix("../tests/read_in_adjacency_matrix/bad_format2.txt",
                             vertex_count, false);
    if (result == NULL)
    {
        printf("Bad format test 2 - Reject empty text file: PASSED\n\n");
    }
    else
    {
        printf("Bad format test 2: FAILED\n\n");
    }

    result = 
    read_in_adjacency_matrix("../tests/read_in_adjacency_matrix/bad_format3.txt",
                             vertex_count, false);
    if (result == NULL)
    {
        printf("Bad format test 3 - No matrix: PASSED\n\n");
    }
    else
    {
        printf("Bad format test 3: FAILED\n\n");
    }

    result = 
    read_in_adjacency_matrix("../tests/read_in_adjacency_matrix/bad_format4.txt",
                             vertex_count, false);
    if (result == NULL)
    {
        printf("Bad format test 4 - One edge over 1000: PASSED\n\n");
    }
    else
    {
        printf("Bad format test 4: FAILED\n\n");
    }

    result = 
    read_in_adjacency_matrix("../tests/read_in_adjacency_matrix/bad_format5.txt",
                             vertex_count, false);
    if (result == NULL)
    {
        printf("Bad format test 5 - Negative edge length: PASSED\n\n");
    }
    else
    {
        printf("Bad format test 5: FAILED\n\n");
    }

    result = 
    read_in_adjacency_matrix("../tests/read_in_adjacency_matrix/bad_format6.txt",
                             vertex_count, false);
    if (result == NULL)
    {
        printf("Bad format test 6 - Not all diagonals == 0: PASSED\n\n");
    }
    else
    {
        printf("Bad format test 6: FAILED\n\n");
    }

    printf("read_in_adjacency_matrix END TESTING\n\n");
    printf("-------------------------\n\n");


    // Testing Floyd Warshall, Serial
    printf("floyd_warshall_serial START TESTING\n\n");
    printf("Simple testing begin:\n\n");
    unsigned int *adj_matrix_1 = 
        read_in_adjacency_matrix("../tests/floyd_warshall"
                                 "/good_format.txt", vertex_count, false);
    floyd_warshall_serial(adj_matrix_1, *vertex_count);

    // Reading in actual matrix
    unsigned int *dist_matrix_correct =
        read_in_adjacency_matrix("../tests/floyd_warshall"
                                 "/good_format_dist.txt", vertex_count, false);
    success = compare_matrices(adj_matrix_1, dist_matrix_correct,
                                    *vertex_count);

    if (success)
    {
        printf("Basic matrix test: PASSED\n\n");
    }
    else
    {
        printf("Basic matrix test: FAILED\n\n");
    }

    adj_matrix_1 = 
        read_in_adjacency_matrix("../tests/floyd_warshall"
                                 "/good_format2.txt", vertex_count, false);
    floyd_warshall_serial(adj_matrix_1, *vertex_count);

    // Reading in actual matrix
    dist_matrix_correct =
        read_in_adjacency_matrix("../tests/floyd_warshall"
                                 "/good_format_dist2.txt", vertex_count, false);

    success = compare_matrices(adj_matrix_1, dist_matrix_correct,
                                    *vertex_count);

    if (success)
    {
        printf("Basic matrix test 2: PASSED\n\n");
    }
    else
    {
        printf("Basic matrix test 2: FAILED\n\n");
    }

    adj_matrix_1 = 
        read_in_adjacency_matrix("../tests/floyd_warshall"
                                 "/good_format3.txt", vertex_count, false);
    floyd_warshall_serial(adj_matrix_1, *vertex_count);

    // Reading in actual matrix
    dist_matrix_correct =
        read_in_adjacency_matrix("../tests/floyd_warshall"
                                 "/good_format_dist3.txt", vertex_count, false);
    success = compare_matrices(adj_matrix_1, dist_matrix_correct,
                                    *vertex_count);

    if (success)
    {
        printf("Basic matrix test 3: PASSED\n\n");
    }
    else
    {
        printf("Basic matrix test 3: FAILED\n\n");
    }
    adj_matrix_1 = 
        read_in_adjacency_matrix("../tests/floyd_warshall"
                                 "/good_format4.txt", vertex_count, false);
    floyd_warshall_serial(adj_matrix_1, *vertex_count);

    // Reading in actual matrix
    dist_matrix_correct =
        read_in_adjacency_matrix("../tests/floyd_warshall"
                                 "/good_format_dist4.txt", vertex_count, false);
    success = compare_matrices(adj_matrix_1, dist_matrix_correct,
                                    *vertex_count);

    if (success)
    {
        printf("Basic matrix test 4 - Many Infinities: PASSED\n\n");
    }
    else
    {
        printf("Basic matrix test 4: FAILED\n\n");
    }
    adj_matrix_1 = 
        read_in_adjacency_matrix("../tests/floyd_warshall"
                                 "/good_format5.txt", vertex_count, false);
    floyd_warshall_serial(adj_matrix_1, *vertex_count);

    // Reading in actual matrix
    dist_matrix_correct =
        read_in_adjacency_matrix("../tests/floyd_warshall"
                                 "/good_format_dist5.txt", vertex_count, false);
    success = compare_matrices(adj_matrix_1, dist_matrix_correct,
                                    *vertex_count);

    if (success)
    {
        printf("Basic matrix test 5 - All 0s: PASSED\n\n");
    }
    else
    {
        printf("Basic matrix test 5: FAILED\n\n");
    }

    printf("Mass testing begin:\n\n");
//    test 
    adj_matrix_1 = 
        read_in_adjacency_matrix(test_file_name2, vertex_count, false);
    floyd_warshall_serial(adj_matrix_1, *vertex_count);

    // Reading in actual matrix
    dist_matrix_correct =
        read_in_adjacency_matrix(result_file_name2, vertex_count, true);
    bool success_2_vertex = compare_matrices(adj_matrix_1, dist_matrix_correct,
                                    *vertex_count);
    // test
    adj_matrix_1 = 
        read_in_adjacency_matrix(test_file_name4, vertex_count, false);
    floyd_warshall_serial(adj_matrix_1, *vertex_count);

    // Reading in actual matrix
    dist_matrix_correct =
        read_in_adjacency_matrix(result_file_name4, vertex_count, true);
    bool success_4_vertex = compare_matrices(adj_matrix_1, dist_matrix_correct,
                                    *vertex_count);
    // test
    adj_matrix_1 = 
        read_in_adjacency_matrix(test_file_name8, vertex_count, false);
    floyd_warshall_serial(adj_matrix_1, *vertex_count);

    // Reading in actual matrix
    dist_matrix_correct =
        read_in_adjacency_matrix(result_file_name8, vertex_count, true);
    bool success_8_vertex = compare_matrices(adj_matrix_1, dist_matrix_correct,
                                    *vertex_count);
    // test
    adj_matrix_1 = 
        read_in_adjacency_matrix(test_file_name16, vertex_count, false);
    floyd_warshall_serial(adj_matrix_1, *vertex_count);

    // Reading in actual matrix
    dist_matrix_correct =
        read_in_adjacency_matrix(result_file_name16, vertex_count, true);
    bool success_16_vertex = compare_matrices(adj_matrix_1, dist_matrix_correct,
                                    *vertex_count);
    // test
    adj_matrix_1 = 
        read_in_adjacency_matrix(test_file_name32, vertex_count, false);
    floyd_warshall_serial(adj_matrix_1, *vertex_count);

    // Reading in actual matrix
    dist_matrix_correct =
        read_in_adjacency_matrix(result_file_name32, vertex_count, true);
    bool success_32_vertex = compare_matrices(adj_matrix_1, dist_matrix_correct,
                                    *vertex_count);
    // test
    adj_matrix_1 = 
        read_in_adjacency_matrix(test_file_name64, vertex_count, false);
    floyd_warshall_serial(adj_matrix_1, *vertex_count);

    // Reading in actual matrix
    dist_matrix_correct =
        read_in_adjacency_matrix(result_file_name64, vertex_count, true);
    bool success_64_vertex = compare_matrices(adj_matrix_1, dist_matrix_correct,
                                    *vertex_count);
    // test
    adj_matrix_1 = 
        read_in_adjacency_matrix(test_file_name128, vertex_count, false);
    floyd_warshall_serial(adj_matrix_1, *vertex_count);

    // Reading in actual matrix
    dist_matrix_correct =
        read_in_adjacency_matrix(result_file_name128, vertex_count, true);
    bool success_128_vertex = compare_matrices(adj_matrix_1, dist_matrix_correct,
                                    *vertex_count);
    // test
    adj_matrix_1 = 
        read_in_adjacency_matrix(test_file_name256, vertex_count, false);
    floyd_warshall_serial(adj_matrix_1, *vertex_count);

    // Reading in actual matrix
    dist_matrix_correct =
        read_in_adjacency_matrix(result_file_name256, vertex_count, true);
    bool success_256_vertex = compare_matrices(adj_matrix_1, dist_matrix_correct,
                                    *vertex_count);
    // test
    adj_matrix_1 = 
        read_in_adjacency_matrix(test_file_name512, vertex_count, false);
    floyd_warshall_serial(adj_matrix_1, *vertex_count);

    // Reading in actual matrix
    dist_matrix_correct =
        read_in_adjacency_matrix(result_file_name512, vertex_count, true);
    bool success_512_vertex = compare_matrices(adj_matrix_1, dist_matrix_correct,
                                    *vertex_count);
    // test
    adj_matrix_1 = 
        read_in_adjacency_matrix(test_file_name1024, vertex_count, false);
    floyd_warshall_serial(adj_matrix_1, *vertex_count);

    // Reading in actual matrix
    dist_matrix_correct =
        read_in_adjacency_matrix(result_file_name1024, vertex_count, true);
    bool success_1024_vertex = compare_matrices(adj_matrix_1, dist_matrix_correct,
                                    *vertex_count);
    int successes = 0;
    if (success_2_vertex) 
        successes++;
    // printf("successes val: %u", successes);
    if (success_4_vertex) 
        successes++;
    if (success_8_vertex) 
        successes++;
    if (success_16_vertex) 
        successes++;
    if (success_32_vertex) 
        successes++;
    if (success_64_vertex) 
        successes++;
    if (success_128_vertex) 
        successes++;
    if (success_256_vertex) 
        successes++;
    if (success_512_vertex) 
        successes++;
    if (success_1024_vertex) 
        successes++;
    printf("Mass testing complete. %u / 10 tests passed\n\n", successes);
            

    


    printf("floyd_warshall_serial END TESTING\n\n");
    printf("-------------------------\n\n");


    // Testing Floyd Warshall, parallel
    printf("floyd_warshall_parallel START TESTING\n\n");
    printf("Simple testing begin:\n\n");
    adj_matrix_1 = 
        read_in_adjacency_matrix("../tests/floyd_warshall"
                                 "/good_format.txt", vertex_count, false);
    floyd_warshall_parallel(adj_matrix_1, *vertex_count, 4);

    // Reading in actual matrix
    dist_matrix_correct =
        read_in_adjacency_matrix("../tests/floyd_warshall"
                                 "/good_format_dist.txt", vertex_count, false);

    success = compare_matrices(dist_matrix_correct, adj_matrix_1, 
                               *vertex_count);

    if (success)
    {
        printf("Basic matrix test - Shortest Paths Already Present: PASSED\n\n");
    }
    else
    {
        printf("Basic matrix test: FAILED\n\n");
    }

    // Testing Floyd Warshall, parallel
    adj_matrix_1 =     adj_matrix_1 = 
        read_in_adjacency_matrix("../tests/floyd_warshall"
                                 "/good_format2.txt", vertex_count, false);
    floyd_warshall_parallel(adj_matrix_1, *vertex_count, 4);

    // Reading in actual matrix
    dist_matrix_correct =
        read_in_adjacency_matrix("../tests/floyd_warshall"
                                 "/good_format_dist2.txt", vertex_count, false);

    success = compare_matrices(dist_matrix_correct, adj_matrix_1,
                               *vertex_count);

    if (success)
    {
        printf("Basic matrix test 2 - All positive ints - Threads == Rows: PASSED\n\n");
    }
    else
    {
        printf("Basic matrix test 2 A: FAILED\n\n");
    }
        read_in_adjacency_matrix("../tests/floyd_warshall"
                                 "/good_format2.txt", vertex_count, false);
    floyd_warshall_parallel(adj_matrix_1, *vertex_count, 4);

    // Reading in actual matrix
    dist_matrix_correct =
        read_in_adjacency_matrix("../tests/floyd_warshall"
                                 "/good_format_dist2.txt", vertex_count, false);

    success = compare_matrices(dist_matrix_correct, adj_matrix_1,
                               *vertex_count);

    if (success)
    {
        printf("Basic matrix test 2 - All positive ints- Threads > Rows: PASSED\n\n");
    }
    else
    {
        printf("Basic matrix test 2: FAILED\n\n");
    }
    adj_matrix_1 = 
        read_in_adjacency_matrix("../tests/floyd_warshall"
                                 "/good_format2.txt", vertex_count, false);
    floyd_warshall_parallel(adj_matrix_1, *vertex_count, 3);

    // Reading in actual matrix
    dist_matrix_correct =
        read_in_adjacency_matrix("../tests/floyd_warshall"
                                 "/good_format_dist2.txt", vertex_count, false);

    success = compare_matrices(dist_matrix_correct, adj_matrix_1,
                               *vertex_count);

    if (success)
    {
        printf("Basic matrix test 2 - All positive ints - Threads == Rows - 1: PASSED\n\n");
    }
    else
    {
        printf("Basic matrix test 2: FAILED\n\n");
    }

    adj_matrix_1 = 
        read_in_adjacency_matrix("../tests/floyd_warshall"
                                 "/good_format3.txt", vertex_count, false);
    floyd_warshall_parallel(adj_matrix_1, *vertex_count, 4);

    // Reading in actual matrix
    dist_matrix_correct =
        read_in_adjacency_matrix("../tests/floyd_warshall"
                                 "/good_format_dist3.txt", vertex_count, false);

    success = compare_matrices(dist_matrix_correct, adj_matrix_1, 
                                    *vertex_count);

    if (success)
    {
        printf("Basic matrix test 3 - Infinity used: PASSED\n\n");
    }
    else
    {
        printf("Basic matrix test 3: FAILED\n\n");
    }
    adj_matrix_1 = 
        read_in_adjacency_matrix("../tests/floyd_warshall"
                                 "/good_format4.txt", vertex_count, false);
    floyd_warshall_parallel(adj_matrix_1, *vertex_count, 4);

    // Reading in actual matrix
    dist_matrix_correct =
        read_in_adjacency_matrix("../tests/floyd_warshall"
                                 "/good_format_dist4.txt", vertex_count, false);
    success = compare_matrices(adj_matrix_1, dist_matrix_correct,
                                    *vertex_count);

    if (success)
    {
        printf("Basic matrix test 4 - Many Infinities: PASSED\n\n");
    }
    else
    {
        printf("Basic matrix test 4: FAILED\n\n");
    }
    adj_matrix_1 = 
        read_in_adjacency_matrix("../tests/floyd_warshall"
                                 "/good_format5.txt", vertex_count, false);
    floyd_warshall_parallel(adj_matrix_1, *vertex_count, 4);

    // Reading in actual matrix
    dist_matrix_correct =
        read_in_adjacency_matrix("../tests/floyd_warshall"
                                 "/good_format_dist5.txt", vertex_count, false);
    success = compare_matrices(adj_matrix_1, dist_matrix_correct,
                                    *vertex_count);

    if (success)
    {
        printf("Basic matrix test 5 - All 0s: PASSED\n\n");
    }
    else
    {
        printf("Basic matrix test 5: FAILED\n\n");
    }

    printf("Mass testing begin:\n\n");

//    test 
    adj_matrix_1 = 
        read_in_adjacency_matrix(test_file_name2, vertex_count, false);
    floyd_warshall_parallel(adj_matrix_1, *vertex_count, 2);

    // Reading in actual matrix
    dist_matrix_correct =
        read_in_adjacency_matrix(result_file_name2, vertex_count, true);
    bool par_success_2_vertex = compare_matrices(adj_matrix_1, dist_matrix_correct,
                                    *vertex_count);
    // test
    adj_matrix_1 = 
        read_in_adjacency_matrix(test_file_name4, vertex_count, false);
    floyd_warshall_parallel(adj_matrix_1, *vertex_count, 4);

    // Reading in actual matrix
    dist_matrix_correct =
        read_in_adjacency_matrix(result_file_name4, vertex_count, true);
    bool par_success_4_vertex = compare_matrices(adj_matrix_1, dist_matrix_correct,
                                    *vertex_count);
    // test
    adj_matrix_1 = 
        read_in_adjacency_matrix(test_file_name8, vertex_count, false);
    floyd_warshall_parallel(adj_matrix_1, *vertex_count, 8);

    // Reading in actual matrix
    dist_matrix_correct =
        read_in_adjacency_matrix(result_file_name8, vertex_count, true);
    bool par_success_8_vertex = compare_matrices(adj_matrix_1, dist_matrix_correct,
                                    *vertex_count);
    // test
    adj_matrix_1 = 
        read_in_adjacency_matrix(test_file_name16, vertex_count, false);
    floyd_warshall_parallel(adj_matrix_1, *vertex_count, 16);

    // Reading in actual matrix
    dist_matrix_correct =
        read_in_adjacency_matrix(result_file_name16, vertex_count, true);
    bool par_success_16_vertex = compare_matrices(adj_matrix_1, dist_matrix_correct,
                                    *vertex_count);
    // test
    adj_matrix_1 = 
        read_in_adjacency_matrix(test_file_name32, vertex_count, false);
    floyd_warshall_parallel(adj_matrix_1, *vertex_count, 32);

    // Reading in actual matrix
    dist_matrix_correct =
        read_in_adjacency_matrix(result_file_name32, vertex_count, true);
    bool par_success_32_vertex = compare_matrices(adj_matrix_1, dist_matrix_correct,
                                    *vertex_count);
    // test
    adj_matrix_1 = 
        read_in_adjacency_matrix(test_file_name64, vertex_count, false);
    floyd_warshall_parallel(adj_matrix_1, *vertex_count, 64);

    // Reading in actual matrix
    dist_matrix_correct =
        read_in_adjacency_matrix(result_file_name64, vertex_count, true);
    bool par_success_64_vertex = compare_matrices(adj_matrix_1, dist_matrix_correct,
                                    *vertex_count);
    // test
    adj_matrix_1 = 
        read_in_adjacency_matrix(test_file_name128, vertex_count, false);
    floyd_warshall_parallel(adj_matrix_1, *vertex_count, 128);

    // Reading in actual matrix
    dist_matrix_correct =
        read_in_adjacency_matrix(result_file_name128, vertex_count, true);
    bool par_success_128_vertex = compare_matrices(adj_matrix_1, dist_matrix_correct,
                                    *vertex_count);
    // test
    adj_matrix_1 = 
        read_in_adjacency_matrix(test_file_name256, vertex_count, false);
    floyd_warshall_parallel(adj_matrix_1, *vertex_count, 256);

    // Reading in actual matrix
    dist_matrix_correct =
        read_in_adjacency_matrix(result_file_name256, vertex_count, true);
    bool par_success_256_vertex = compare_matrices(adj_matrix_1, dist_matrix_correct,
                                    *vertex_count);
    // test
    adj_matrix_1 = 
        read_in_adjacency_matrix(test_file_name512, vertex_count, false);
    floyd_warshall_parallel(adj_matrix_1, *vertex_count, 512);

    // Reading in actual matrix
    dist_matrix_correct =
        read_in_adjacency_matrix(result_file_name512, vertex_count, true);
    bool par_success_512_vertex = compare_matrices(adj_matrix_1, dist_matrix_correct,
                                    *vertex_count);
    // test
    adj_matrix_1 = 
        read_in_adjacency_matrix(test_file_name1024, vertex_count, false);
    floyd_warshall_parallel(adj_matrix_1, *vertex_count, 1024);

    // Reading in actual matrix
    dist_matrix_correct =
        read_in_adjacency_matrix(result_file_name1024, vertex_count, true);
    bool par_success_1024_vertex = compare_matrices(adj_matrix_1, dist_matrix_correct,
                                    *vertex_count);
    successes = 0;
    if (par_success_2_vertex) 
        successes++;
    // printf("successes val: %u", successes);
    if (par_success_4_vertex) 
        successes++;
    if (par_success_8_vertex) 
        successes++;
    if (par_success_16_vertex) 
        successes++;
    if (par_success_32_vertex) 
        successes++;
    if (par_success_64_vertex) 
        successes++;
    if (par_success_128_vertex) 
        successes++;
    if (par_success_256_vertex) 
        successes++;
    if (par_success_512_vertex) 
        successes++;
    if (par_success_1024_vertex) 
        successes++;
    printf("Mass testing complete. %u / 10 tests passed\n\n", successes);
            

    printf("floyd_warshall_parallel END TESTING\n\n");

    printf("------------------------------------\n\n");
    printf("Onto EXPERIMENTATION\n\n");
    printf("------------------------------------\n\n");
    printf("T = 1, N = 2, 4, 6, 8 , 16, 32, 64, 128, 256, 512, 1024\n\n");
    run_n_experiments_serial("../experiments/serial_test_1");
    run_n_experiments_parallel("../experiments/parallel_test_1", 1);

    printf("T = 2, N = 2, 4, 6, 8 , 16, 32, 64, 128, 256, 512, 1024\n\n");
    run_n_experiments_serial("../experiments/serial_test_2");
    run_n_experiments_parallel("../experiments/parallel_test_2", 2);

    printf("T = 4, N = 2, 4, 6, 8 , 16, 32, 64, 128, 256, 512, 1024\n\n");
    run_n_experiments_serial("../experiments/serial_test_4");
    run_n_experiments_parallel("../experiments/parallel_test_4", 4);

    printf("T = 8, N = 2, 4, 6, 8 , 16, 32, 64, 128, 256, 512, 1024\n\n");
    run_n_experiments_serial("../experiments/serial_test_8");
    run_n_experiments_parallel("../experiments/parallel_test_8", 8);
    
    printf("T = 16, N = 2, 4, 6, 8 , 16, 32, 64, 128, 256, 512, 1024\n\n");
    run_n_experiments_serial("../experiments/serial_test_16");
    run_n_experiments_parallel("../experiments/parallel_test_16", 16);

    printf("T = 32, N = 2, 4, 6, 8 , 16, 32, 64, 128, 256, 512, 1024\n\n");
    run_n_experiments_serial("../experiments/serial_test_32");
    run_n_experiments_parallel("../experiments/parallel_test_32", 32);

    printf("T = 64, N = 2, 4, 6, 8 , 16, 32, 64, 128, 256, 512, 1024\n\n");
    run_n_experiments_serial("../experiments/serial_test_64");
    run_n_experiments_parallel("../experiments/parallel_test_64", 64);

    return 0;
}
