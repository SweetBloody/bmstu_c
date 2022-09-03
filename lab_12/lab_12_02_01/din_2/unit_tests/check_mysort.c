#include <stdlib.h>
#include <check.h>
#include <windows.h>
#include "check_mysort.h"

typedef void (__cdecl *fn_mysort_t) (void *, size_t, size_t, int (*comparator)(const void *, const void *));
typedef int (__cdecl *fn_compare_int_t) (const void *, const void *);
typedef int (__cdecl *fn_compare_char_t) (const void *, const void *);
typedef int (__cdecl *fn_compare_double_t) (const void *, const void *);

// Тесты функции mysort
START_TEST(test_sort_sorted_array_int)
{
    HMODULE plib;
    fn_mysort_t mysort;
    fn_compare_int_t compare_int;
    int a[] = {1, 2, 3, 4}, b[] = {1, 2, 3, 4};

    plib = LoadLibrary("./process_2.dll");
    mysort = (fn_mysort_t) GetProcAddress(plib, "mysort");
    compare_int = (fn_compare_int_t) GetProcAddress(plib, "compare_int");
    mysort(a, 4, sizeof(a[0]), compare_int);

    ck_assert_mem_eq(a, b, 4 * sizeof(a[0]));
    FreeLibrary(plib);
}
END_TEST

START_TEST(test_sort_reversed_array_int)
{
    HMODULE plib;
    fn_mysort_t mysort;
    fn_compare_int_t compare_int;
    int a[] = {4, 3, 2, 1}, b[] = {1, 2, 3, 4};

    plib = LoadLibrary("./process_2.dll");
    mysort = (fn_mysort_t) GetProcAddress(plib, "mysort");
    compare_int = (fn_compare_int_t) GetProcAddress(plib, "compare_int");
    mysort(a, 4, sizeof(a[0]), compare_int);

    ck_assert_mem_eq(a, b, 4 * sizeof(a[0]));
    FreeLibrary(plib);
}
END_TEST

START_TEST(test_sort_mixed_array_int)
{
    HMODULE plib;
    fn_mysort_t mysort;
    fn_compare_int_t compare_int;
    int a[] = {10, -3, -4, 8, 0}, b[] = {-4, -3, 0, 8, 10};

    plib = LoadLibrary("./process_2.dll");
    mysort = (fn_mysort_t) GetProcAddress(plib, "mysort");
    compare_int = (fn_compare_int_t) GetProcAddress(plib, "compare_int");
    mysort(a, 5, sizeof(a[0]), compare_int);

    ck_assert_mem_eq(a, b, 5 * sizeof(a[0]));
    FreeLibrary(plib);
}
END_TEST

START_TEST(test_sort_equal_number_array_int)
{
    HMODULE plib;
    fn_mysort_t mysort;
    fn_compare_int_t compare_int;
    int a[] = {1, 1, 1, 1, 1}, b[] = {1, 1, 1, 1, 1};

    plib = LoadLibrary("./process_2.dll");
    mysort = (fn_mysort_t) GetProcAddress(plib, "mysort");
    compare_int = (fn_compare_int_t) GetProcAddress(plib, "compare_int");
    mysort(a, 5, sizeof(a[0]), compare_int);

    ck_assert_mem_eq(a, b, 5 * sizeof(a[0]));
    FreeLibrary(plib);
}
END_TEST

START_TEST(test_sort_equal_elems_array_char)
{
    HMODULE plib;
    fn_mysort_t mysort;
    fn_compare_char_t compare_char;
    char a[] = {'a', 'a', 'a', 'a'}, b[] = {'a', 'a', 'a', 'a'};

    plib = LoadLibrary("./process_2.dll");
    mysort = (fn_mysort_t) GetProcAddress(plib, "mysort");
    compare_char = (fn_compare_char_t) GetProcAddress(plib, "compare_char");
    mysort(a, 4, sizeof(a[0]), compare_char);

    ck_assert_mem_eq(a, b, 4 * sizeof(a[0]));
    FreeLibrary(plib);
}
END_TEST

START_TEST(test_sort_mixed_array_char)
{
    HMODULE plib;
    fn_mysort_t mysort;
    fn_compare_char_t compare_char;
    char a[] = {'d', 'c', 'b', 'a'}, b[] = {'a', 'b', 'c', 'd'};

    plib = LoadLibrary("./process_2.dll");
    mysort = (fn_mysort_t) GetProcAddress(plib, "mysort");
    compare_char = (fn_compare_char_t) GetProcAddress(plib, "compare_char");
    mysort(a, 4, sizeof(a[0]), compare_char);

    ck_assert_mem_eq(a, b, 4 * sizeof(a[0]));
    FreeLibrary(plib);
}
END_TEST

START_TEST(test_sort_equal_elems_array_double)
{
    HMODULE plib;
    fn_mysort_t mysort;
    fn_compare_double_t compare_double;
    double a[] = {1.125, 1.125, 1.125, 1.125}, b[] = {1.125, 1.125, 1.125, 1.125};

    plib = LoadLibrary("./process_2.dll");
    mysort = (fn_mysort_t) GetProcAddress(plib, "mysort");
    compare_double = (fn_compare_double_t) GetProcAddress(plib, "compare_double");
    mysort(a, 4, sizeof(a[0]), compare_double);

    ck_assert_mem_eq(a, b, 4 * sizeof(a[0]));
    FreeLibrary(plib);
}
END_TEST

START_TEST(test_sort_mixed_array_double)
{
    HMODULE plib;
    fn_mysort_t mysort;
    fn_compare_double_t compare_double;
    double a[] = {3.45, -3.45, 0, -6.5432}, b[] = {-6.5432, -3.45, 0, 3.45};

    plib = LoadLibrary("./process_2.dll");
    mysort = (fn_mysort_t) GetProcAddress(plib, "mysort");
    compare_double = (fn_compare_double_t) GetProcAddress(plib, "compare_double");
    mysort(a, 4, sizeof(a[0]), compare_double);

    ck_assert_mem_eq(a, b, 4 * sizeof(a[0]));
    FreeLibrary(plib);
}
END_TEST

Suite* sort_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    // Создадим тестовый набор для тестирования функции sort
    s = suite_create("sort");

    // Создадим тестовый случай из функций-тестов, которые проверяют работу
    // sort для корректных параметров
    tc_pos = tcase_create("positives");
    // Добавим в tc_pos соответствующие функции-тесты
    tcase_add_test(tc_pos, test_sort_sorted_array_int);
    tcase_add_test(tc_pos, test_sort_reversed_array_int);
    tcase_add_test(tc_pos, test_sort_mixed_array_int);
    tcase_add_test(tc_pos, test_sort_equal_number_array_int);
    tcase_add_test(tc_pos, test_sort_mixed_array_char);
    tcase_add_test(tc_pos, test_sort_equal_elems_array_char);
    tcase_add_test(tc_pos, test_sort_equal_elems_array_double);
    tcase_add_test(tc_pos, test_sort_mixed_array_double);

    // Добавим сформированный тестовый случай в тестовый набор
    suite_add_tcase(s, tc_pos);

    return s;
}