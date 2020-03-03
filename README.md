# TP_C_task-1

[![Build Status](https://travis-ci.org/shysa/TP_C_task-1.svg?branch=base)](https://travis-ci.org/shysa/TP_C_task-1)
[![Coverage Status](https://coveralls.io/repos/github/shysa/TP_C_task-1/badge.svg?branch=base)](https://coveralls.io/github/shysa/TP_C_task-1?branch=base)

### Условие ИЗ№1:
Составить программу формирования на базе заданной прямоугольной матрицы трех других, первая из которых содержит плотно упакованную совокупность столбцов с номерами 1, 4, 7, …, вторая — такую же совокупность столбцов с номерами 2, 5, 8, …, а третья — все остальные. Операцию оформить как функцию, принимающую на вход двойной указатель на матрицу и ее размеры по каждому измерению. На выход функция должна вернуть указатель на трехэлементный массив указателей на результирующие структуры (тройной указатель).

Требования к оформлению:
Программа должна быть реализована на языке C и работать для произвольных наборов входных данных (в том числе и ошибочных), вводимых пользователем с клавиатуры. Должна быть выполнена грамотная декомпозиция на функции и файлы.
Помимо самой программы необходимо:
- разработать набор юнит-тестов, проверяющих корректную работу реализованных функций. Обеспечить максимальное покрытие исходного кода тестами;
- оформить задачу в виде Merge Request отдельной ветки в master.
**Внимание: в ветке master никакого кода быть не должно!**
- развернуть CI, в рамках которого автоматизировать сборку проекта, прохождение юнит-тестов под valgrind, генерацию отчёта о покрытии кода тестами, линтера и статического анализатора исходного кода;
- после прохождения всех проверок необходимо отправить код на ревью своему преподавателю;
- ревью - процесс итерационный. До наступления дедлайна можно проходить несколько итераций, улучшая свою оценку. Решения после дедлайна не принимаются;
- дедлайн - РК №1, 11.03.2020