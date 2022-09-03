#ifndef LAB_08_CDIO_H
#define LAB_08_CDIO_H

#include <stdio.h>

// Чтение размерности матрицы из файла
int input_matrix_size(char *file_name, int *n, int *m);

// Создание матрицы
double **create_matrix(int n, int m);

// Освобождение памяти матрицы
void free_matrix(double **matrix, double *start_string);

// Заполнение матрицы
int input_matrix(char *file_name, double **matrix, int n, int m);

// Вывод матрицы в файл
void print_matrix_to_file(char *file_name, double **matrix, int n, int m);

// Создание массива
int *create_array(int rows);

// Вывод решения СЛАУ в файл
void print_array_to_file(char *file_name, double **matrix, int columns, int *array, int length);

// Вывод сообщений об ошибках
void print_errors(int ch);

#endif //LAB_08_CDIO_H
