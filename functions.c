#include "include.h"

int** get_matrix_memory(const size_t rows, const size_t cols) {
    if (!rows || !cols) {
        return NULL;
    }

    int **matrix = (int **) calloc(rows, sizeof(int*));
    if (!matrix) {
        return NULL;
    }
    for (size_t i = 0; i < rows; i++) {
        matrix[i] = (int *) calloc(cols, sizeof(int));
        if (!matrix[i]) {
            free_matrix_memory(matrix, i);
        }
    }
    return matrix;
}

int read_matrix(FILE * input, int** matrix, const size_t rows, const size_t cols) {
    if (!matrix) {
        return -1;
    }

    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < cols; j++) {
            if (!fscanf(input,"%d", &matrix[i][j])) {
                free_matrix_memory(matrix, rows);
                return -1;
            }
        }
    }

    return 0;
}

int print_matrix(int** matrix, const size_t rows, const size_t cols) {
    if (!matrix) {
        return -1;
    }
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    return 0;
}

int*** forming_matrix(const int** matrix, const size_t rows, const size_t cols) {
    int ***result = (int***) calloc(NUM_MATRIXES, sizeof(int**));
    if (!result) {
        return NULL;
    }

    size_t new_cols[NUM_MATRIXES];

    for (size_t i = 0; i < NUM_MATRIXES; i++) {
        new_cols[i] = cols / NUM_MATRIXES + (cols % NUM_MATRIXES > i ? 1 : 0);
    }

    for (size_t i = 0; i < NUM_MATRIXES; i++) {
        if (new_cols[i]) {
            result[i] = get_matrix_memory(rows, new_cols[i]);
            if (result[i]) {
                if (copy_matrix(&result[i], (const int **) matrix, rows, new_cols[i], i)) {
                    free_result(result, rows);
                    return NULL;
                }
            } else {
                free_result(result, rows);
                return NULL;
            }
        }
    }

    return result;
}

int copy_matrix(int ***result, const int** matrix, const size_t rows, const size_t cols, const size_t start) {
    if (!result || !matrix) {
        return -1;
    }
    for (size_t i = 0; i < rows; i++) {
        for (size_t round = start, new_cols = 0; new_cols < cols; round+=NUM_MATRIXES, new_cols++) {
            (*result)[i][new_cols] = matrix[i][round];
        }
    }

    return 0;
}

int free_result(int*** result, size_t rows) {
    if (!result) {
        return -1;
    }
    for (size_t i = 0; i < NUM_MATRIXES; i++) {
        free_matrix_memory(result[i], rows);
    }
    free(result);

    return 0;
}

int free_matrix_memory(int** matrix, size_t rows) {
    if (!matrix) {
        return -1;
    }
    for (size_t i = 0; i < rows; i++) {
        if (matrix[i]) {
            free(matrix[i]);
        }
    }
    free(matrix);

    return 0;
}

int read_sizes(FILE * input, size_t *rows, size_t *cols) {
    if (!fscanf(input, "%zu %zu", rows, cols)) {
        return -1;
    }
    return 0;
}
