#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_MATRIXES 3

int** get_matrix_memory(size_t rows, size_t cols);
int read_matrix(FILE * input, int** matrix, size_t rows, size_t cols);
int print_matrix(int** matrix, size_t rows, size_t cols);
int*** forming_matrix(const int** matrix, size_t rows, size_t cols);
int copy_matrix(int ***result, const int** matrix, size_t rows, size_t cols, size_t start);
int free_result(int*** result, size_t rows);
int free_matrix_memory(int** matrix, size_t rows);
int read_sizes(FILE * input, size_t *rows, size_t *cols);