#ifndef LAB_07_CDIO_H
#define LAB_07_CDIO_H

// Считает количество чисел в файле
int count_numbers_amount(char *file_name, int *amount);

// Создание и заполнение массива
int create_array(char *file_name, int **array, int numbers_amount);

// Вывод чисел из массива в файл
void print_array_to_file(char *file_name, int *array_st, int *array_end);

// Вывод сообщений об ошибках
void print_errors(int ch);

#endif //LAB_07_CDIO_H
