#include <check.h>
#include "check_addition.h"
#include "process.h"
#include "cdio.h"

// Тесты функции matrix_addition
START_TEST(test_addition_eq_rows)
{
    double a[3][3] = {{1, 2, 3}, {1, 2, 3}, {1, 2, 3}};
    double *matrix_1[3] = {a[0], a[1], a[2]};
    double b[3][3] = {{1, 1, 1}, {1, 1, 1}, {1, 1, 1}};
    double *matrix_2[3] = {b[0], b[1], b[2]};
    double c[3][3] = {{2, 3, 4}, {2, 3, 4}, {2, 3, 4}};
    double *matrix_3[3] = {c[0], c[1], c[2]};

    double **d = create_matrix(3, 3);
    double *str = d[0];
    int ch;

    matrix_addition(matrix_1, matrix_2, d, 3, 3);

    ch = matrix_eq(matrix_3, d, 3, 3);

    ck_assert_int_eq(ch, 0);

    free_matrix(d, str);
}
END_TEST

START_TEST(test_addition_mix_matr)
{
    double a[3][3] = {{1, 2, 3}, {-5, 8, 10}, {0, 4, 0}};
    double *matrix_1[3] = {a[0], a[1], a[2]};
    double b[3][3] = {{1, -5, 4}, {2, 1, -8}, {-1, 0, 3}};
    double *matrix_2[3] = {b[0], b[1], b[2]};
    double c[3][3] = {{2, -3, 7}, {-3, 9, 2}, {-1, 4, 3}};
    double *matrix_3[3] = {c[0], c[1], c[2]};

    double **d = create_matrix(3, 3);
    double *str = d[0];
    int ch;

    matrix_addition(matrix_1, matrix_2, d, 3, 3);

    ch = matrix_eq(matrix_3, d, 3, 3);

    ck_assert_int_eq(ch, 0);

    free_matrix(d, str);
}
END_TEST

START_TEST(test_addition_nul_matr)
{
    double a[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
    double *matrix_1[3] = {a[0], a[1], a[2]};
    double b[3][3] = {{1, 1, 1}, {1, 1, 1}, {1, 1, 1}};
    double *matrix_2[3] = {b[0], b[1], b[2]};
    double c[3][3] = {{1, 1, 1}, {1, 1, 1}, {1, 1, 1}};
    double *matrix_3[3] = {c[0], c[1], c[2]};

    double **d = create_matrix(3, 3);
    double *str = d[0];
    int ch;

    matrix_addition(matrix_1, matrix_2, d, 3, 3);

    ch = matrix_eq(matrix_3, d, 3, 3);

    ck_assert_int_eq(ch, 0);

    free_matrix(d, str);
}
END_TEST

START_TEST(test_addition_get_nul_matr)
{
    double a[3][3] = {{1, 2, 3}, {1, 2, 3}, {1, 2, 3}};
    double *matrix_1[3] = {a[0], a[1], a[2]};
    double b[3][3] = {{-1, -2, -3}, {-1, -2, -3}, {-1, -2, -3}};
    double *matrix_2[3] = {b[0], b[1], b[2]};
    double c[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
    double *matrix_3[3] = {c[0], c[1], c[2]};

    double **d = create_matrix(3, 3);
    double *str = d[0];
    int ch;

    matrix_addition(matrix_1, matrix_2, d, 3, 3);

    ch = matrix_eq(matrix_3, d, 3, 3);

    ck_assert_int_eq(ch, 0);

    free_matrix(d, str);
}
END_TEST

Suite* addition_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    // Создадим тестовый набор для тестирования функции sort
    s = suite_create("Addition:");

    // Создадим тестовый случай из функций-тестов, которые проверяют работу
    // sort для корректных параметров
    tc_pos = tcase_create("positives");
    // Добавим в tc_pos соответствующие функции-тесты
    tcase_add_test(tc_pos, test_addition_eq_rows);
    tcase_add_test(tc_pos, test_addition_mix_matr);
    tcase_add_test(tc_pos, test_addition_nul_matr);
    tcase_add_test(tc_pos, test_addition_get_nul_matr);

    // Добавим сформированный тестовый случай в тестовый набор
    suite_add_tcase(s, tc_pos);

    return s;
}