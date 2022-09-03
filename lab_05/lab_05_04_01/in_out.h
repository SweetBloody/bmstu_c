#ifndef IN_OUT_H

#define IN_OUT_H

#include "const.h"

int file_check(char **argv); // Проверка существования файла

int write_to_file(FILE *f, struct student *students, int num); // Функция создания и заполнения файла

int read_file(char **argv, struct student *students, int *students_number); // Функция чтения полей структуры из файла и составления массива структур

void print_students(struct student *students, int num); // Функция вывода массива структур

#endif // IN_OUT_H
