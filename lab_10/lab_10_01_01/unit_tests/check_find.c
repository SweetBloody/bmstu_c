#include <check.h>
#include "check_find.h"
#include "list.h"
#include "cdio.h"

// Тесты функции find
START_TEST(test_find_begin)
{
    node_t *head = NULL, *tail = NULL, *res;
    int number = 0;

    create_list(&head, &tail, 7);
    res = find(head, (void*) &number, compare_int);
    ck_assert_int_eq(*(int*)res->data, number);

    free_list(&head, &tail);
    ck_assert_ptr_null(head);
    ck_assert_ptr_null(tail);
}
END_TEST

START_TEST(test_find_mid)
{
    node_t *head = NULL, *tail = NULL, *res;
    int number = 3;

    create_list(&head, &tail, 7);
    res = find(head, (void*) &number, compare_int);

    ck_assert_int_eq(*(int*)res->data, number);

    free_list(&head, &tail);
    ck_assert_ptr_null(head);
    ck_assert_ptr_null(tail);
}
END_TEST

START_TEST(test_find_end)
{
    node_t *head = NULL, *tail = NULL, *res;
    int number = 6;

    create_list(&head, &tail, 7);
    res = find(head, (void*) &number, compare_int);

    ck_assert_int_eq(*(int*)res->data, number);

    free_list(&head, &tail);
    ck_assert_ptr_null(head);
    ck_assert_ptr_null(tail);
}
END_TEST

START_TEST(test_find_mix)
{
    node_t *head = NULL, *tail = NULL, *res;
    int number = 12;

    create_list(&head, &tail, 15);
    res = find(head, (void*) &number, compare_int);

    ck_assert_int_eq(*(int*)res->data, number);

    free_list(&head, &tail);
    ck_assert_ptr_null(head);
    ck_assert_ptr_null(tail);
}
END_TEST

START_TEST(test_find_no_elem)
{
    node_t *head = NULL, *tail = NULL, *res;
    int number = 9, flag = 1;

    create_list(&head, &tail, 8);
    res = find(head, (void*) &number, compare_int);

    if (!res)
        flag = 0;

    ck_assert_int_eq(flag, 0);

    free_list(&head, &tail);
    ck_assert_ptr_null(head);
    ck_assert_ptr_null(tail);
}
END_TEST

Suite* find_suite(void)
{
    Suite *s;
    TCase *tc_pos;
    TCase *tc_neg;

    s = suite_create("find:");

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_find_begin);
    tcase_add_test(tc_pos, test_find_mid);
    tcase_add_test(tc_pos, test_find_end);
    tcase_add_test(tc_pos, test_find_mix);
    suite_add_tcase(s, tc_pos);

    tc_neg = tcase_create("negatives");
    tcase_add_test(tc_neg, test_find_no_elem);
    suite_add_tcase(s, tc_neg);

    return s;
}