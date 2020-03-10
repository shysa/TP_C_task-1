/*
    Условие ИЗ№1:
    Составить программу формирования на базе заданной прямоугольной матрицы трех других,
    первая из которых содержит плотно упакованную совокупность столбцов с номерами 1, 4, 7, …,
    вторая — такую же совокупность столбцов с номерами 2, 5, 8, …, а третья — все остальные.
    Операцию оформить как функцию, принимающую на вход двойной указатель на матрицу и ее
    размеры по каждому измерению. На выход функция должна вернуть указатель на трехэлементный
    массив указателей на результирующие структуры (тройной указатель).
*/

#include "include.h"


int main() {
    size_t rows = 0;
    size_t cols = 0;
    int **matrix = NULL;
    int ***result = NULL;

    if (read_sizes(stdin, &rows, &cols)) {
        printf("Wrong matrix sizes\n");
        return -1;
    }

    matrix = get_matrix_memory(rows, cols);
    if (!matrix) {
        printf("Memory allocation error\n");
        return -1;
    }

    if (read_matrix(stdin, matrix, rows, cols)) {
        printf("Wrong matrix data\n");
        return -1;
    }

    if (print_matrix(matrix, rows, cols)) {
        printf("Matrix can't be printed\n");
        return -1;
    }

    result = forming_matrix((const int **) matrix, rows, cols);
    if (!result) {
        printf("Can't form result\n");
        return -1;
    }

    if (free_result(result, rows)) {
        printf("Memory can't be freed\n");
        return -1;
    }
    if (free_matrix_memory(matrix, rows)) {
        printf("Memory can't be freed");
        return -1;
    }

    return 0;
}
