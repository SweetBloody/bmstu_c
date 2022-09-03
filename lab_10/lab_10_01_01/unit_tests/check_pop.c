#include <check.h>
#include <stdlib.h>
#include "check_pop.h"
#include "list.h"
#include "cdio.h"

// Тесты функции pop_back
START_TEST(test_pop_back_one_elem_list)
{
    node_t *head_1 = NULL, *tail_1 = NULL;
    void *data;

    create_list(&head_1, &tail_1, 1);
    data = pop_back(&head_1);
    tail_1 = get_tail(&head_1);

    ck_assert_int_eq(*(int*)data, 0);
    ck_assert_ptr_null(head_1);
    ck_assert_ptr_null(tail_1);

    free(data);
}
END_TEST

START_TEST(test_pop_back_short_list)
{
    node_t *head_1 = NULL, *tail_1 = NULL;
    node_t *head_2 = NULL, *tail_2 = NULL;
    void *data;

    create_list(&head_1, &tail_1, 3);
    create_list(&head_2, &tail_2, 2);
    data = pop_back(&head_1);
    tail_1 = get_tail(&head_1);

    ck_assert_int_eq(*(int*)data, 2);
    ck_assert_int_eq(list_cmp(head_1, head_2, compare_int), 0);

    free(data);
    free_list(&head_1, &tail_1);
    free_list(&head_2, &tail_2);
    ck_assert_ptr_null(head_1);
    ck_assert_ptr_null(tail_1);
    ck_assert_ptr_null(head_2);
    ck_assert_ptr_null(tail_2);

}
END_TEST

START_TEST(test_pop_back_medium_list)
{
    node_t *head_1 = NULL, *tail_1 = NULL;
    node_t *head_2 = NULL, *tail_2 = NULL;
    void *data;

    create_list(&head_1, &tail_1, 15);
    create_list(&head_2, &tail_2, 14);
    data = pop_back(&head_1);
    tail_1 = get_tail(&head_1);

    ck_assert_int_eq(*(int*)data, 14);
    ck_assert_int_eq(list_cmp(head_1, head_2, compare_int), 0);

    free(data);
    free_list(&head_1, &tail_1);
    free_list(&head_2, &tail_2);
    ck_assert_ptr_null(head_1);
    ck_assert_ptr_null(tail_1);
    ck_assert_ptr_null(head_2);
    ck_assert_ptr_null(tail_2);
}
END_TEST

START_TEST(test_pop_back_long_list)
{
    node_t *head_1 = NULL, *tail_1 = NULL;
    node_t *head_2 = NULL, *tail_2 = NULL;
    void *data;

    create_list(&head_1, &tail_1, 30);
    create_list(&head_2, &tail_2, 29);
    data = pop_back(&head_1);
    tail_1 = get_tail(&head_1);

    ck_assert_int_eq(*(int*)data, 29);
    ck_assert_int_eq(list_cmp(head_1, head_2, compare_int), 0);

    free(data);
    free_list(&head_1, &tail_1);
    free_list(&head_2, &tail_2);
    ck_assert_ptr_null(head_1);
    ck_assert_ptr_null(tail_1);
    ck_assert_ptr_null(head_2);
    ck_assert_ptr_null(tail_2);
}
END_TEST

START_TEST(test_pop_back_empty_list)
{
    node_t *head_1 = NULL;
    void *data;

    data = pop_back(&head_1);

    ck_assert_ptr_null(data);
}
END_TEST

Suite* pop_back_suite(void)
{
    Suite *s;
    TCase *tc_pos;
    TCase *tc_neg;

    s = suite_create("pop_back:");

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_pop_back_one_elem_list);
    tcase_add_test(tc_pos, test_pop_back_short_list);
    tcase_add_test(tc_pos, test_pop_back_medium_list);
    tcase_add_test(tc_pos, test_pop_back_long_list);
    suite_add_tcase(s, tc_pos);

    tc_neg = tcase_create("negatives");
    tcase_add_test(tc_neg, test_pop_back_empty_list);
    suite_add_tcase(s, tc_neg);

    return s;
}