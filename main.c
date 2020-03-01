/*
    Условие ИЗ№1:
    Составить программу формирования на базе заданной прямоугольной матрицы трех других,
    первая из которых содержит плотно упакованную совокупность столбцов с номерами 1, 4, 7, …,
    вторая — такую же совокупность столбцов с номерами 2, 5, 8, …, а третья — все остальные.
    Операцию оформить как функцию, принимающую на вход двойной указатель на матрицу и ее
    размеры по каждому измерению. На выход функция должна вернуть указатель на трехэлементный
    массив указателей на результирующие структуры (тройной указатель).
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int** GetMatrixMemory(int rows, int cols);
void ReadMatrix(int** matrix, size_t rows, size_t cols);
void PrintMatrix(int** matrix, size_t rows, size_t cols);
int*** FormingMatrixes(int** matrix, size_t rows, size_t cols);
void CopingMatrix(int** result[], int** matrix, size_t rows, size_t cols, size_t start);
void FreeResult(int*** result, size_t rows);
void FreeMatrixMemory(int** matrix, size_t rows);


int main() {
    int rows;
    int cols;
    int **matrix;
    int ***result;

    printf("Enter size of matrix: ");
    scanf("%d %d", &rows, &cols);

    matrix = GetMatrixMemory(rows, cols);
    ReadMatrix(matrix, rows, cols);
    PrintMatrix(matrix, rows, cols);

    result = FormingMatrixes(matrix, rows, cols);

    FreeResult(result, rows);
    FreeMatrixMemory(matrix, rows);

    return 0;
}

int** GetMatrixMemory(int rows, int cols) {
    if (!rows || !cols) {
        printf("Rows or columns can't be 0\n");
        return NULL;
    }
    if (rows < 0 || cols < 0) {
        printf("Rows or columns can't be less than 0\n");
        return NULL;
    }

    int **matrix = (int **) malloc(rows * sizeof(int*));
    if (!matrix) {
        printf("Memory allocation error\n");
        return NULL;
    }
    for (size_t i = 0; i < rows; i++) {
        matrix[i] = (int *) malloc(cols * sizeof(int));
        if (!matrix[i]) {
            printf("Memory allocation error\n");
            FreeMatrixMemory(matrix, i);
            return NULL;
        }
    }
    return matrix;
}

void ReadMatrix(int** matrix, size_t rows, size_t cols) {
    if (!matrix) {
        printf("Matrix can't be read\n");
        return;
    }
    printf("Enter the matrix:\n");
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

void PrintMatrix(int** matrix, size_t rows, size_t cols) {
    if (!matrix) {
        printf("Matrix can't be output\n");
        return;
    }
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < cols; j++) {
            printf("%2d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int*** FormingMatrixes(int** matrix, size_t rows, size_t cols) {
    int ***result = (int***) malloc(3 * sizeof(int**));
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

void FreeResult(int*** result, size_t rows) {
    if (!result) {
        printf("Memory can't be freed\n");
        return;
    }
    for (size_t i = 0; i < 3; i++) {
        FreeMatrixMemory(result[i], rows);
    }
    free(result);
}

void FreeMatrixMemory(int** matrix, size_t rows) {
    if (!matrix) {
        printf("Memory can't be freed\n");
        return;
    }
    for (size_t i = 0; i < rows; i++) {
        if (matrix[i]) {
            free(matrix[i]);
        }
    }
    free(matrix);
}