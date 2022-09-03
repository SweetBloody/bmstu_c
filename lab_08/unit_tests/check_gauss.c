#include <check.h>
#include "check_gauss.h"
#include "process.h"

// Тесты функции matrix_addition
START_TEST(test_gauss_mix_matr_4x5)
{
    double a[4][5] = {{20, 8, -35, 0, 1}, {-12, 0, 0, 0, 3}, {7, 4, -1, 23, 0}, {0, -2, 0, 100, -23}};
    double *matrix[4] = {a[0], a[1], a[2], a[3]};
    int result_array[4] = {0, 1, 2, 3};
    double result[4] = {-0.250000, 1.623228, 0.199595, -0.197535};
    int ch;

    gauss(matrix, 4, 5, result_array);

    ch = gauss_res_check(matrix, 4, 5, result_array, result);

    ck_assert_int_eq(ch, 0);
}
END_TEST

START_TEST(test_gauss_mix_matr_3x4)
{
    double a[3][4] = {{3, 0, 1, -3}, {-9, 7, 13, 0}, {8, 0, -1, 2}};
    double *matrix[3] = {a[0], a[1], a[2]};
    int result_array[] = {0, 1, 2};
    double result[3] = {-0.090909, 4.948052, -2.727273};
    int ch;

    gauss(matrix, 3, 4, result_array);

    ch = gauss_res_check(matrix, 3, 4, result_array, result);

    ck_assert_int_eq(ch, 0);
}
END_TEST

START_TEST(test_gauss_e_matr)
{
    double a[3][4] = {{1, 0, 0, -123}, {0, 1, 0, 4}, {0, 0, 1, 33}};
    double *matrix[3] = {a[0], a[1], a[2]};
    int result_array[] = {0, 1, 2};
    double result[3] = {-123, 4, 33};
    int ch;

    gauss(matrix, 3, 4, result_array);

    ch = gauss_res_check(matrix, 3, 4, result_array, result);

    ck_assert_int_eq(ch, 0);
}
END_TEST

START_TEST(test_gauss_eq_str_matr)
{
    double a[3][4] = {{1, 0, 3, -123}, {1, 1, 0, 4}, {1, 0, 3, -123}};
    double *matrix[3] = {a[0], a[1], a[2]};
    int result_array[] = {0, 1, 2};
    int ch;

    ch = gauss(matrix, 3, 4, result_array);

    ck_assert_int_eq(ch, 11);
}
END_TEST

START_TEST(test_gauss_prop_str_matr)
{
    double a[3][4] = {{1, 0, 3, -123}, {1, 1, 0, 4}, {2, 2, 0, 8}};
    double *matrix[3] = {a[0], a[1], a[2]};
    int result_array[] = {0, 1, 2};
    int ch;

    ch = gauss(matrix, 3, 4, result_array);

    ck_assert_int_eq(ch, 11);
}
END_TEST

START_TEST(test_gauss_null_col_matr)
{
    double a[3][4] = {{1, 0, 0, -123}, {1, 1, 0, 4}, {2, -25, 0, 8}};
    double *matrix[3] = {a[0], a[1], a[2]};
    int result_array[] = {0, 1, 2};
    int ch;

    ch = gauss(matrix, 3, 4, result_array);

    ck_assert_int_eq(ch, 11);
}
END_TEST

Suite* gauss_suite(void)
{
    Suite *s;
    TCase *tc_pos;
    TCase *tc_neg;

    // Создадим тестовый набор для тестирования функции sort
    s = suite_create("Gauss:");

    // Создадим тестовый случай из функций-тестов, которые проверяют работу
    // sort для корректных параметров
    tc_pos = tcase_create("positives");
    // Добавим в tc_pos соответствующие функции-тесты
    tcase_add_test(tc_pos, test_gauss_mix_matr_4x5);
    tcase_add_test(tc_pos, test_gauss_mix_matr_3x4);
    tcase_add_test(tc_pos, test_gauss_e_matr);

    // Добавим сформированный тестовый случай в тестовый набор
    suite_add_tcase(s, tc_pos);

    tc_neg = tcase_create("negatives");
    tcase_add_test(tc_neg, test_gauss_eq_str_matr);
    tcase_add_test(tc_neg, test_gauss_prop_str_matr);
    tcase_add_test(tc_neg, test_gauss_null_col_matr);
    suite_add_tcase(s, tc_neg);

    return s;
}