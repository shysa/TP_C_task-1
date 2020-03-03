#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int** GetMatrixMemory(size_t rows, size_t cols);
int ReadMatrix(int** matrix, size_t rows, size_t cols);
int PrintMatrix(int** matrix, size_t rows, size_t cols);
int*** FormingMatrixes(int** matrix, size_t rows, size_t cols);
void CopingMatrix(int** result[], int** matrix, size_t rows, size_t cols, size_t start);
int FreeResult(int*** result, size_t rows);
int FreeMatrixMemory(int** matrix, size_t rows);
int Reading(FILE * input, size_t *rows, size_t *cols);