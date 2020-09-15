# Parallel Floyd Warshall Algorithm


## About

This code sample was turned in for an assignment in a class I took on Parallel Computing at my university. It was a project focused class, with a heavy emphasis on C programming implementations of parallel computing algorithms and synchronization methods.

In this particular assignment, I implemented a parallel version of the Floyd-Warshall algorithm (as well as the serial version, for performance comparison). The Floyd-Warshall algorithm is a shortest path algorithm for graphs, that specifically computes the shortest distances between every pair of vertices in the input graph. Graphs are input through an adjacency matrix written in a text file - an adjacency matrix is a way to represent a graph as a matrix.

The basic idea behind the parallel implementation is to divide the adjacency matrix into rows, and have different threads each compute upon different rows. This works well for the Floyd Warshall algorithm, because it is essentially a double for loop. There is some concurrency control required, which was accompished with semaphores. Semaphores provided a very quick locking mechanism, compared to something like a pthread mutex.

I found this assignment (and the class overall) very enjoyable, and I am happy to share some of the work that I did. We had to write our own implementations and then write tests and experiments for our implementations. I found this refreshing compared to other CS courses where we only had to pass some tests provided by the instructor. 
  

## Directories and Navigation 

`src` contains the source code for creating the algorithm implementations. It also contains a Makefile used to make the three compiled programs talked about below.

The `experiments` directory contains output files from running several experiments on the algorithm. These results were graphed and discussed in `ddicarlo_hw1_writeup.pdf`. 

The `graphing` directory contains some generated CSVs from running the experiments, as well as an R markdown file (`graphing/figure_generator.Rmd`) used to generate figures for `ddicarlo_hw1_writeup.pdf`.

`main_parallel_out` and `main_serial_out` are directories that hold the text output from the parallel and serial programs. 

`tests` contains generated input text files for testing the floyd warshall algorithm as well as unit testing the read_in_adjacency_matrix function. These tests were generated using a python script that I have misplaced (it wasn't submitted with my homework).

`ddicarlo_hw1_writeup.pdf` discusses some of the choices I made with my implementation, and provides an analysis of the algorithm.
  

## Implementation Code

There are several files used to compile three different programs. The files are:

* `src/floyd_warshall.c` - functions used to run in parallel and serial implementations of the Floyd Warshall algorithm. 
* `src/import.c` - function inside is used to read in an adjacency matrix from a file, in the format described in "Guidelines of Adjacency Graph Formatting" below.
* `src/testing.c` - file where I wrote my own unit tests for the various functions used, as well as some experiments I had to do for the assignment.
* `src/stopwatch.c` - file provided to us by the course instructor, used to get a stopwatch argument for timing our implementations.
  

## Compiled Programs

The programs generated from running the Makefile are: 

* `src/output` - Comprehensive testing script that prints to the screen, writes
           experiments results to files in the ../experiments folder
* `src/main_serial` - Command line program for running the serial Floyd Warshall algo
* `src/main_parallel` - Command line program for running the parallel Floyd Warshall algo

`src/output` is run without any arguments

`src/main_serial` should be run with only one argument, the path to the input 
adjacency matrix.

`src/main_parallel` should be run with exactly two arguments, the path to the input
adjacency matrix as well as the number of threads desired to run the program in
parallel. Note that the program maxes out on using min(num_threads, num_vertices)
number of threads due to implementation design.
   

## Adjacency Matrix Formatting

Quoting from the assignment guidelines:

"Your goal is to take a text file representing an adjacency matrix and output a text file containing a table with the shortest paths between each pair of vertices.  The first line of the input file should have an integer representing the number n of vertices in the graph.  The remainder of the text file should have n lines containing n integers each of which represents the weight of a directed edge connecting vertex i to vertex j.  Let the maximum edge length be 1000.  Find a way to represent an infinite weight; i.e. no direct edge from i to j.  Entry k on line k should be 0 to represent that the shortest path from a node to itself has no cost.  For the output file, line i should represent starting at vertex i, and the jth entry of line i should be the shortest path from i to j."

To represent infinity, I use the letter I. Otherwise, the text formatting is mostly as described. Each integer (or "I") will be followed by exactly one " " or whitespace character, for ease of using fscanf. Each line ends in "\n", including the last one, meaning the file will end in a newline. This is also for simplicity of using fscanf. A sample input text file is below:

`4`  

`0 2 I 5`  

`2 0 3 4`  

`1 1 0 3`  

`2 4 2 0 `
