#ifndef CONST_H

#define CONST_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "file_process.h" // Функции обработки файла
#include "file_numbers.h" // Функции обработки чисел в файле

#define OK 0 // Нет ошибок
#define INCORRECT_ARGS 1 // Неправильные аргументы командной строки
#define NO_DATA 2 // Нет данных
#define INCORRECT_INPUT 3 // Некорректный ввод
#define FILE_READ_ERR 4 // Ошибка чтения файла
#define FILE_CLOSE_ERR 5 // Ошибка закрытия файла
#define INCORRECT_INDEX 6 // Некорректное значение позиции
#define FILE_ERR -1 // Ошибка размера и данных файла

#endif // CONST_H
