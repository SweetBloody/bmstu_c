#ifndef CONST_H
#define CONST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "struct.h"   // Структуры
#include "cdio.h"     // Ввод/вывод/проверки
#include "process.h"  // Основные функции обработки

#define TITLE_MAX 25        // Максимальная длина названия
#define NAME_MAX 25         // Максимальная длина фамилии
#define MAX_LEN_STRUCT 15   // Максимальное количество структур

#define OK 0                  // Нет ошибок
#define INCORRECT_ARGS 1      // Неправильные аргументы командной строки
#define FILE_OPEN_ERR 2       // Ошибка открытия файла
#define FILE_ERR 3            // Ошибка данных файла
#define FILE_CLOSE_ERR 4      // Ошибка закрытия файла
#define EMPTY_FILE 5          // Пустой файл
#define INCORRECT_INPUT 20    // Некорректный ввод
#define STR_OVERFLOW 21       // Переполнение фамилии/имени
#define EMPTY_STR 22          // Пустая строка
#define NOT_FOUND 10          // Не найден нужный фильм
#define NUM_STRUCT_OVERFLOW 9 // Избыток структур

#endif // CONST_H
