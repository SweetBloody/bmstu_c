#ifndef CONST_H

#define CONST_H

#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <inttypes.h>
#include "struct.h" // Структуры
#include "in_out.h" // Функции ввода/вывода и проверки файла
#include "b_process.h" // Функции для вывода в указанный файл студентов, чья фамилия начинается с заданной подстроки
#include "c_process.h" // Функции удаления из файла студентов, чей средний балл меньше среднего балла по файлу

#define SURNAME_MAX 25 // Максимальная длина фамилии
#define NAME_MAX 10 // Максимальная длина имени
#define MARKS 4 // Количество оценок

#define OK 0 // Нет ошибок
#define FILE_OPEN_ERR 1 // Ошибка открытия файла
#define FILE_ERR 2 // Ошибка данных файла
#define FILE_CLOSE_ERR 3 // Ошибка закрытия файла
#define INCORRECT_INPUT 4 // Некорректный ввод
#define SURNAME_OVERFLOW 5 // Переполнение фамилии
#define NAME_OVERFLOW 6 // Переполнение имени
#define EMPTY_STR 7 // Пустая строка
#define NO_FIT_SURNAMES 8 // Нет подходящих фамилий
#define INCORRECT_ARGS 53 // Неправильные аргументы командной строки

#endif // CONST_H
