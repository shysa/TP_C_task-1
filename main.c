/*
    Условие ИЗ№1:
    Составить программу формирования на базе заданной прямоугольной матрицы трех других,
    первая из которых содержит плотно упакованную совокупность столбцов с номерами 1, 4, 7, …,
    вторая — такую же совокупность столбцов с номерами 2, 5, 8, …, а третья — все остальные.
    Операцию оформить как функцию, принимающую на вход двойной указатель на матрицу и ее
    размеры по каждому измерению. На выход функция должна вернуть указатель на трехэлементный
    массив указателей на результирующие структуры (тройной указатель).
*/

#include "header.h"


int main() {
    size_t rows = 0;
    size_t cols = 0;
    int **matrix = NULL;
    int ***result = NULL;

    printf("Enter size of matrix: ");
    Reading(stdin, &rows, &cols);

    matrix = GetMatrixMemory(rows, cols);
    ReadMatrix(matrix, rows, cols);
    PrintMatrix(matrix, rows, cols);

    result = FormingMatrixes(matrix, rows, cols);

    FreeResult(result, rows);
    FreeMatrixMemory(matrix, rows);

    return 0;
}
