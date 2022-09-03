#ifndef LAB_07_CONST_H
#define LAB_07_CONST_H

// Коды ошибок
#define OK 0                // Нет ошибок
#define INCORRECT_ARGS 1    // Неправильные аргументы командной строки
#define NO_DATA 2           // Нет данных
#define INCORRECT_INPUT 3   // Некорректный ввод
#define FILE_OPEN_ERR 4     // Ошибка чтения файла
#define FILE_CLOSE_ERR 5    // Ошибка закрытия файла
#define FILE_ERR 6          // Ошибка размера и данных файла
#define MEMORY_GET_ERROR 7  // Ошибка выделения памяти
#define GOT_EMPTY_ARRAY -8   // В результате фильтрации получен пустой массив

#define EPS 1.0e-7          // Точность сравнения double

#endif
