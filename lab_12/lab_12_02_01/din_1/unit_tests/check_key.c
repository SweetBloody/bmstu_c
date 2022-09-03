#include <stdlib.h>
#include <check.h>
#include "check_key.h"
#include "process.h"

// Тесты функции key
START_TEST(test_key_first_elem_neg_array)
{
    int a[] = {-10, -3, -4, 8, 0}, ch;
    int *new_a_st, *new_a_end;

    ch = key(a, a + 5, &new_a_st, &new_a_end, 1);

    ck_assert_int_eq(ch, -8);
}
END_TEST

START_TEST(test_key_one_number_array)
{
    int a[] = {10, -3, -4, 8, 0}, b[] = {10};
    int *new_a_st, *new_a_end, ch;

    ch = key(a, a + 5, &new_a_st, &new_a_end, 1);
    new_a_st = malloc(ch * sizeof(int));
    key(a, a + 5, &new_a_st, &new_a_end, 2);

    ck_assert_mem_eq(new_a_st, b, 1 * sizeof(int));

    free(new_a_st);
}
END_TEST

START_TEST(test_key_two_numbers_array)
{
    int a[] = {10, 3, -4, 8, 0}, b[] = {10, 3};
    int *new_a_st, *new_a_end, ch;

    ch = key(a, a + 5, &new_a_st, &new_a_end, 1);
    new_a_st = malloc(ch * sizeof(int));
    key(a, a + 5, &new_a_st, &new_a_end, 2);

    ck_assert_mem_eq(new_a_st, b, 2 * sizeof(int));

    free(new_a_st);
}
END_TEST

START_TEST(test_key_two_neg_numbers_array)
{
    int a[] = {10, 3, 4, -8, 0, -10, 1}, b[] = {10, 3, 4};
    int *new_a_st, *new_a_end, ch;

    ch = key(a, a + 7, &new_a_st, &new_a_end, 1);
    new_a_st = malloc(ch * sizeof(int));
    key(a, a + 5, &new_a_st, &new_a_end, 2);

    ck_assert_mem_eq(new_a_st, b, 3 * sizeof(int));

    free(new_a_st);
}
END_TEST

START_TEST(test_key_full_array)
{
    int a[] = {10, 3, 4, 8, 0, 10, 1}, b[] = {10, 3, 4, 8, 0, 10, 1};
    int *new_a_st, *new_a_end, ch;

    ch = key(a, a + 7, &new_a_st, &new_a_end, 1);
    new_a_st = malloc(ch * sizeof(int));
    key(a, a + 7, &new_a_st, &new_a_end, 2);

    ck_assert_mem_eq(new_a_st, b, 7 * sizeof(int));

    free(new_a_st);
}
END_TEST

Suite* key_suite(void)
{
    Suite *s;
    TCase *tc_pos;
    TCase *tc_neg;

    // Создадим тестовый набор для тестирования функции key
    s = suite_create("key");

    // Создадим тестовый случай из функций-тестов, которые проверяют разного
    // рода ошибочные ситуации при вызове key
    tc_neg = tcase_create("negatives");
    // Добавим в tc_neg соответствующие функции-тесты
    tcase_add_test(tc_neg, test_key_first_elem_neg_array);

    // Добавим сформированный тестовый случай в тестовый набор
    suite_add_tcase(s, tc_neg);

    // Создадим тестовый случай из функций-тестов, которые проверяют работу
    // calc_avg для корректных параметров
    tc_pos = tcase_create("positives");
    // Добавим в tc_pos соответствующие функции-тесты
    tcase_add_test(tc_pos, test_key_one_number_array);
    tcase_add_test(tc_pos, test_key_two_numbers_array);
    tcase_add_test(tc_pos, test_key_two_neg_numbers_array);
    tcase_add_test(tc_pos, test_key_full_array);

    // Добавим сформированный тестовый случай в тестовый набор
    suite_add_tcase(s, tc_pos);

    return s;
}
