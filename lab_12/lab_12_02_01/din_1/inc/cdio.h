#ifndef LAB_12_02_01_CDIO_H
#define LAB_12_02_01_CDIO_H

#ifdef ARR_EXPORTS
#define ARR_DLL __declspec(dllexport)
#else
#define ARR_DLL __declspec(dllimport)
#endif

#define ARR_DECL __cdecl

// Считает количество чисел в файле
ARR_DLL int ARR_DECL count_numbers_amount(char *file_name, int *amount);

// Создание и заполнение массива
ARR_DLL int ARR_DECL create_array(char *file_name, int **array, int numbers_amount);

// Вывод чисел из массива в файл
ARR_DLL void ARR_DECL print_array_to_file(char *file_name, int *array_st, int *array_end);

// Вывод сообщений об ошибках
ARR_DLL void ARR_DECL print_errors(int ch);

#endif //LAB_12_02_01_CDIO_H
