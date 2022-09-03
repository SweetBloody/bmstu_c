#include <check.h>
#include "process.h"
#include "cdio.h"
#include "check_multi.h"

// Тесты функции matrix_addition
START_TEST(test_multi_nul_matr)
{
    double a[3][3] = {{1, 2, 3}, {1, 2, 3}, {1, 2, 3}};
    double *matrix_1[3] = {a[0], a[1], a[2]};
    double b[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
    double *matrix_2[3] = {b[0], b[1], b[2]};
    double c[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
    double *matrix_3[3] = {c[0], c[1], c[2]};
    double **d = create_matrix(3, 3);
    double *str = d[0];
    int ch;

    matrix_multiply(matrix_1, 3, 3, matrix_2, 3, d);

    ch = matrix_eq(matrix_3, d, 3, 3);

    ck_assert_int_eq(ch, 0);

    free_matrix(d, str);
}
END_TEST

START_TEST(test_multi_mix_matr)
{
    double a[2][3] = {{4, 5, -6}, {8, 0, 5}};
    double *matrix_1[2] = {a[0], a[1]};
    double b[3][2] = {{7, 5}, {-1, 10}, {6, 4}};
    double *matrix_2[3] = {b[0], b[1], b[2]};
    double c[2][2] = {{-13, 46}, {86, 60}};
    double *matrix_3[2] = {c[0], c[1]};
    double **d = create_matrix(2, 2);
    double *str = d[0];
    int ch;

    matrix_multiply(matrix_1, 2, 3, matrix_2, 2, d);

    ch = matrix_eq(matrix_3, d, 2, 2);

    ck_assert_int_eq(ch, 0);

    free_matrix(d, str);
}
END_TEST

START_TEST(test_multi_e_matr)
{
    double a[3][3] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
    double *matrix_1[3] = {a[0], a[1], a[2]};
    double b[3][2] = {{4, 5}, {-4, 8}, {6, 1}};
    double *matrix_2[3] = {b[0], b[1], b[2]};
    double c[3][2] = {{4, 5}, {-4, 8}, {6, 1}};
    double *matrix_3[3] = {c[0], c[1], c[2]};
    double **d = create_matrix(3, 2);
    double *str = d[0];
    int ch;

    matrix_multiply(matrix_1, 3, 3, matrix_2, 2, d);
    ch = matrix_eq(matrix_3, d, 3, 2);

    ck_assert_int_eq(ch, 0);

    free_matrix(d, str);
}
END_TEST

Suite* multi_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    // Создадим тестовый набор для тестирования функции sort
    s = suite_create("Multi:");

    // Создадим тестовый случай из функций-тестов, которые проверяют работу
    // sort для корректных параметров
    tc_pos = tcase_create("positives");
    // Добавим в tc_pos соответствующие функции-тесты
    tcase_add_test(tc_pos, test_multi_nul_matr);
    tcase_add_test(tc_pos, test_multi_mix_matr);
    tcase_add_test(tc_pos, test_multi_e_matr);

    // Добавим сформированный тестовый случай в тестовый набор
    suite_add_tcase(s, tc_pos);

    return s;
}