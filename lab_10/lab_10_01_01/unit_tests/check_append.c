#include <check.h>
#include "check_append.h"
#include "list.h"
#include "cdio.h"

//Тесты функции append
START_TEST(test_append_one_elem_lists)
{
    node_t *head_1 = NULL, *tail_1 = NULL;
    node_t *head_2 = NULL, *tail_2 = NULL;
    node_t *head_3 = NULL, *tail_3 = NULL;
    int array[] = {0, 0};

    create_list(&head_1, &tail_1, 1);
    create_list(&head_2, &tail_2, 1);
    create_list_by_array(&head_3, &tail_3, array, 2);
    append(&head_1, &head_2);
    tail_1 = get_tail(&head_1);
    tail_2 = get_tail(&head_2);

    ck_assert_int_eq(list_cmp(head_1, head_3, compare_int), 0);

    free_list(&head_1, &tail_1);
    free_list(&head_3, &tail_3);

    ck_assert_ptr_null(head_1);
    ck_assert_ptr_null(tail_1);
    ck_assert_ptr_null(head_2);
    ck_assert_ptr_null(tail_2);
    ck_assert_ptr_null(head_3);
    ck_assert_ptr_null(tail_3);
}
END_TEST

START_TEST(test_append_two_elem_lists)
{
    node_t *head_1 = NULL, *tail_1 = NULL;
    node_t *head_2 = NULL, *tail_2 = NULL;
    node_t *head_3 = NULL, *tail_3 = NULL;
    int array[] = {0, 1, 0, 1};

    create_list(&head_1, &tail_1, 2);
    create_list(&head_2, &tail_2, 2);
    create_list_by_array(&head_3, &tail_3, array, 4);
    append(&head_1, &head_2);
    tail_1 = get_tail(&head_1);
    tail_2 = get_tail(&head_2);

    ck_assert_int_eq(list_cmp(head_1, head_3, compare_int), 0);

    free_list(&head_1, &tail_1);
    free_list(&head_3, &tail_3);

    ck_assert_ptr_null(head_1);
    ck_assert_ptr_null(tail_1);
    ck_assert_ptr_null(head_2);
    ck_assert_ptr_null(tail_2);
    ck_assert_ptr_null(head_3);
    ck_assert_ptr_null(tail_3);
}
END_TEST

START_TEST(test_append_many_elem_lists)
{
    node_t *head_1 = NULL, *tail_1 = NULL;
    node_t *head_2 = NULL, *tail_2 = NULL;
    node_t *head_3 = NULL, *tail_3 = NULL;
    int array[] = {0, 1, 2, 3, 4, 5, 0, 1, 2, 3, 4, 5};

    create_list(&head_1, &tail_1, 6);
    create_list(&head_2, &tail_2, 6);
    create_list_by_array(&head_3, &tail_3, array, 12);
    append(&head_1, &head_2);
    tail_1 = get_tail(&head_1);
    tail_2 = get_tail(&head_2);

    ck_assert_int_eq(list_cmp(head_1, head_3, compare_int), 0);

    free_list(&head_1, &tail_1);
    free_list(&head_3, &tail_3);

    ck_assert_ptr_null(head_1);
    ck_assert_ptr_null(tail_1);
    ck_assert_ptr_null(head_2);
    ck_assert_ptr_null(tail_2);
    ck_assert_ptr_null(head_3);
    ck_assert_ptr_null(tail_3);
}
END_TEST

START_TEST(test_append_diff_lists)
{
    node_t *head_1 = NULL, *tail_1 = NULL;
    node_t *head_2 = NULL, *tail_2 = NULL;
    node_t *head_3 = NULL, *tail_3 = NULL;
    int array[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 1, 2, 3, 4, 5};

    create_list(&head_1, &tail_1, 10);
    create_list(&head_2, &tail_2, 6);
    create_list_by_array(&head_3, &tail_3, array, 16);
    append(&head_1, &head_2);
    tail_1 = get_tail(&head_1);
    tail_2 = get_tail(&head_2);

    ck_assert_int_eq(list_cmp(head_1, head_3, compare_int), 0);

    free_list(&head_1, &tail_1);
    free_list(&head_3, &tail_3);

    ck_assert_ptr_null(head_1);
    ck_assert_ptr_null(tail_1);
    ck_assert_ptr_null(head_2);
    ck_assert_ptr_null(tail_2);
    ck_assert_ptr_null(head_3);
    ck_assert_ptr_null(tail_3);
}
END_TEST

START_TEST(test_append_first_list_empty)
{
    node_t *head_1 = NULL, *tail_1 = NULL;
    node_t *head_2 = NULL, *tail_2 = NULL;
    node_t *head_3 = NULL, *tail_3 = NULL;
    int array[] = {0, 1, 2, 3, 4, 5};

    create_list(&head_2, &tail_2, 6);
    create_list_by_array(&head_3, &tail_3, array, 6);
    append(&head_1, &head_2);
    tail_1 = get_tail(&head_1);
    tail_2 = get_tail(&head_2);

    ck_assert_int_eq(list_cmp(head_1, head_3, compare_int), 0);

    free_list(&head_1, &tail_1);
    free_list(&head_3, &tail_3);

    ck_assert_ptr_null(head_1);
    ck_assert_ptr_null(tail_1);
    ck_assert_ptr_null(head_2);
    ck_assert_ptr_null(tail_2);
    ck_assert_ptr_null(head_3);
    ck_assert_ptr_null(tail_3);
}
END_TEST

START_TEST(test_append_second_list_empty)
{
    node_t *head_1 = NULL, *tail_1 = NULL;
    node_t *head_2 = NULL;
    node_t *head_3 = NULL, *tail_3 = NULL;
    int array[] = {0, 1, 2, 3, 4, 5, 6, 7, 8};

    create_list(&head_1, &tail_1, 9);
    create_list_by_array(&head_3, &tail_3, array, 9);
    append(&head_1, &head_2);
    tail_1 = get_tail(&head_1);

    ck_assert_int_eq(list_cmp(head_1, head_3, compare_int), 0);

    free_list(&head_1, &tail_1);
    free_list(&head_3, &tail_3);

    ck_assert_ptr_null(head_1);
    ck_assert_ptr_null(tail_1);
    ck_assert_ptr_null(head_2);
    ck_assert_ptr_null(head_3);
    ck_assert_ptr_null(tail_3);
}
END_TEST

START_TEST(test_append_both_lists_empty)
{
    node_t *head_1 = NULL;
    node_t *head_2 = NULL;

    append(&head_1, &head_2);

    ck_assert_ptr_null(head_1);
    ck_assert_ptr_null(head_2);
}
END_TEST

Suite* append_suite(void)
{
    Suite *s;
    TCase *tc_pos;
    TCase *tc_neg;

    s = suite_create("append:");

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_append_one_elem_lists);
    tcase_add_test(tc_pos, test_append_two_elem_lists);
    tcase_add_test(tc_pos, test_append_many_elem_lists);
    tcase_add_test(tc_pos, test_append_diff_lists);
    tcase_add_test(tc_pos, test_append_first_list_empty);
    tcase_add_test(tc_pos, test_append_second_list_empty);
    suite_add_tcase(s, tc_pos);

    tc_neg = tcase_create("negatives");
    tcase_add_test(tc_neg, test_append_both_lists_empty);
    suite_add_tcase(s, tc_neg);

    return s;
}