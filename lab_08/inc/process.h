#ifndef LAB_08_PROCESS_H
#define LAB_08_PROCESS_H

// Проверка на возможность сложения матриц
int addition_check(int n1, int m1, int n2, int m2);

// Сложение матриц
void matrix_addition(double **matrix_1, double **matrix_2, double **matrix_res, int rows, int columns);

// Проверка на возможность умножения матриц
int multiply_check(int m1, int n2);

// Умножение матриц
void matrix_multiply(double **matrix_1, int row_1, int column_1, double **matrix_2, int column_2, double **matrix_res);

// Проверка на наличие нулевой строки
int matrix_null_row_check(double **matrix, int rows, int columns);

// Проверка на наличие нулевого столбца
int matrix_null_col_check(double **matrix, int rows, int columns);

// Метод Гаусса
int gauss(double **matrix, int rows, int columns, int *result_array);

// Проверка на равенство матриц
int matrix_eq(double **matrix_1, double **matrix_2, int rows, int columns);

// Проверка решения СЛАУ методом Гаусса
int gauss_res_check(double **matrix, int rows, int columns, int *result_array, double *result);

#endif //LAB_08_PROCESS_H
