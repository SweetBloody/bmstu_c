#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <windows.h>
#include "file_process.h"
#include "const.h"

// Типы функций экспортируемых из библиотек
typedef int (__cdecl *fn_key_t) (const int *, const int *, int **, int **, int);
typedef void (__cdecl *fn_mysort_t) (void *, size_t, size_t, int (*comparator)(const void *, const void *));
typedef int (__cdecl *fn_cnumam_t) (char *, int *);
typedef int (__cdecl *fn_create_arr_t) (char *, int **, int);
typedef void (__cdecl *fn_print_arr_t) (char *, int *, int *);
typedef void (__cdecl *fn_print_err_t) (int);
typedef int (__cdecl *fn_compare_int_t) (const void *, const void *);

int main(int argc, char **argv)
{
    HMODULE clib, plib;
    fn_key_t key;
    fn_mysort_t mysort;
    fn_cnumam_t count_numbers_amount;
    fn_create_arr_t create_array;
    fn_print_arr_t print_array_to_file;
    fn_print_err_t print_errors;
    fn_compare_int_t compare_int;
    int ch, number_amount = 0, *array, *new_array_st, *new_array_end;

    clib = LoadLibrary("cdio_2.dll");
    if (!clib)
    {
        printf("Error: cannot load library.\n");
        return LOAD_LIB_ERR;
    }

    plib = LoadLibrary("process_2.dll");
    if (!plib)
    {
        printf("Error: cannot load library.\n");
        FreeLibrary(clib);
        return LOAD_LIB_ERR;
    }

    // Получаем функции их библиотеки
    print_errors = (fn_print_err_t) GetProcAddress(clib, "print_errors");
    if (!print_errors)
    {
        printf("Error: cannot load function.\n");
        FreeLibrary(clib);
        FreeLibrary(plib);
        return LOAD_FUNC_ERR;
    }

    count_numbers_amount = (fn_cnumam_t) GetProcAddress(clib, "count_numbers_amount");
    if (!count_numbers_amount)
    {
        printf("Error: cannot load function.\n");
        FreeLibrary(clib);
        FreeLibrary(plib);
        return LOAD_FUNC_ERR;
    }

    create_array = (fn_create_arr_t) GetProcAddress(clib, "create_array");
    if (!create_array)
    {
        printf("Error: cannot load function.\n");
        FreeLibrary(clib);
        FreeLibrary(plib);
        return LOAD_FUNC_ERR;
    }

    print_array_to_file = (fn_print_arr_t) GetProcAddress(clib, "print_array_to_file");
    if (!print_array_to_file)
    {
        printf("Error: cannot load function.\n");
        FreeLibrary(clib);
        FreeLibrary(plib);
        return LOAD_FUNC_ERR;
    }

    key = (fn_key_t) GetProcAddress(plib, "key");
    if (!key)
    {
        printf("Error: cannot load function.\n");
        FreeLibrary(clib);
        FreeLibrary(plib);
        return LOAD_FUNC_ERR;
    }

    mysort = (fn_mysort_t) GetProcAddress(plib, "mysort");
    if (!mysort)
    {
        printf("Error: cannot load function.\n");
        FreeLibrary(clib);
        FreeLibrary(plib);
        return LOAD_FUNC_ERR;
    }

    compare_int = (fn_compare_int_t) GetProcAddress(plib, "compare_int");
    if (!compare_int)
    {
        printf("Error: cannot load function.\n");
        FreeLibrary(clib);
        FreeLibrary(plib);
        return LOAD_FUNC_ERR;
    }

    ch = args_check(argc, argv);

    if (ch != OK)
    {
        print_errors(ch);
        FreeLibrary(clib);
        FreeLibrary(plib);
        return ch;
    }

    ch = file_check(argv[1]);

    if (ch != OK)
    {
        print_errors(ch);
        FreeLibrary(clib);
        FreeLibrary(plib);
        return ch;
    }

    ch = count_numbers_amount(argv[1], &number_amount);

    if (ch != OK)
    {
        print_errors(ch);
        FreeLibrary(clib);
        FreeLibrary(plib);
        return ch;
    }

    array = malloc(number_amount * sizeof(int));

    if (array == NULL)
    {
        print_errors(MEMORY_GET_ERROR);
        FreeLibrary(clib);
        FreeLibrary(plib);
        return MEMORY_GET_ERROR;
    }

    ch = create_array(argv[1], &array, number_amount);

    if (ch != OK)
    {
        print_errors(ch);
        FreeLibrary(clib);
        FreeLibrary(plib);
        return ch;
    }


    if (argc == 4 && strcmp(argv[3], "f") == 0)
    {
        ch = key(array, array + number_amount, &new_array_st, &new_array_end, 1);
        if (ch == MEMORY_GET_ERROR)
        {
            print_errors(ch);
            FreeLibrary(clib);
            FreeLibrary(plib);
            return ch;
        }

        new_array_st = malloc(ch * sizeof(int));

        if (new_array_st == NULL)
        {
            print_errors(MEMORY_GET_ERROR);
            FreeLibrary(clib);
            FreeLibrary(plib);
            return MEMORY_GET_ERROR;
        }

        ch = key(array, array + number_amount, &new_array_st, &new_array_end, 2);

        if (ch != OK)
        {
            print_errors(ch);
            FreeLibrary(clib);
            FreeLibrary(plib);
            free(array);
            return ch;
        }

        free(array);
        mysort(new_array_st, new_array_end - new_array_st, sizeof(int), compare_int);
        print_array_to_file(argv[2], new_array_st, new_array_end);
        free(new_array_st);
    }
    else
    {
        mysort(array, number_amount, sizeof(int), compare_int);
        print_array_to_file(argv[2], array, array + number_amount);
        free(array);
    }

    FreeLibrary(clib);
    FreeLibrary(plib);

    return ch;
}
