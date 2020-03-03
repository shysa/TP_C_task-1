#include "header.h"

int** GetMatrixMemory(size_t rows, size_t cols) {
    if (!rows || !cols) {
        printf("Rows or columns can't be 0\n");
        return NULL;
    }

    int **matrix = (int **) calloc(rows, sizeof(int*));
    if (!matrix) {
        printf("Memory allocation error\n");
        return NULL;
    }
    for (size_t i = 0; i < rows; i++) {
        matrix[i] = (int *) calloc(cols, sizeof(int));
        if (!matrix[i]) {
            printf("Memory allocation error\n");
            FreeMatrixMemory(matrix, i);
            return NULL;
        }
    }
    return matrix;
}

int ReadMatrix(int** matrix, size_t rows, size_t cols) {
    if (!matrix) {
        printf("Matrix can't be read\n");
        return 1;
    }
    printf("Enter the matrix:\n");
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    return 0;
}

int PrintMatrix(int** matrix, size_t rows, size_t cols) {
    if (!matrix) {
        printf("Matrix can't be output\n");
        return 1;
    }
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < cols; j++) {
            printf("%2d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    return 0;
}

int*** FormingMatrixes(int** matrix, size_t rows, size_t cols) {
    int ***result = (int***) calloc(3, sizeof(int**));
    if (!result) {
        printf("Memory allocation error\n");
        return NULL;
    }

    size_t new_cols[3];

    new_cols[0] = cols / 3 + (cols % 3 > 0 ? 1 : 0);
    new_cols[1] = cols / 3 + (cols % 3 > 1 ? 1 : 0);
    new_cols[2] = cols / 3;

    for (size_t i = 0; i < 3; i++) {
        result[i] = GetMatrixMemory(rows, new_cols[i]);
        if (result[i]) {
            CopingMatrix(&result[i], matrix, rows, new_cols[i], i);
        }
    }

    return result;
}

void CopingMatrix(int** result[], int** matrix, size_t rows, size_t cols, size_t start) {
    for (size_t i = 0; i < rows; i++) {
        for (size_t round = start, new_cols = 0; new_cols < cols; round+=3, new_cols++) {
            (*result)[i][new_cols] = matrix[i][round];
        }
    }
}

int FreeResult(int*** result, size_t rows) {
    if (!result) {
        printf("Memory can't be freed\n");
        return 1;
    }
    for (size_t i = 0; i < 3; i++) {
        FreeMatrixMemory(result[i], rows);
    }
    free(result);

    return 0;
}

int FreeMatrixMemory(int** matrix, size_t rows) {
    if (!matrix) {
        printf("Memory can't be freed\n");
        return 1;
    }
    for (size_t i = 0; i < rows; i++) {
        if (matrix[i]) {
            free(matrix[i]);
        }
    }
    free(matrix);

    return 0;
}