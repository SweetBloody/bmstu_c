#include <check.h>
#include "check_sort.h"
#include "list.h"
#include "cdio.h"

//Тесты функции sort
START_TEST(test_sort_one_elem_list)
{
    node_t *head_1 = NULL, *tail_1 = NULL;
    node_t *head_2 = NULL, *tail_2 = NULL;
    int array[] = {0};

    create_list_by_array(&head_1, &tail_1, array, 1);
    create_list(&head_2, &tail_2, 1);
    head_1 = sort(head_1, compare_int);
    tail_1 = get_tail(&head_1);

    ck_assert_int_eq(list_cmp(head_1, head_2, compare_int), 0);

    free_list(&head_1, &tail_1);
    free_list(&head_2, &tail_2);

    ck_assert_ptr_null(head_1);
    ck_assert_ptr_null(tail_1);
    ck_assert_ptr_null(head_2);
    ck_assert_ptr_null(tail_2);
}
END_TEST

START_TEST(test_sort_equal_numbers_list)
{
    node_t *head_1 = NULL, *tail_1 = NULL;
    node_t *head_2 = NULL, *tail_2 = NULL;
    int array_1[] = {5, 5, 5, 5, 5, 5, 5, 5};
    int array_2[] = {5, 5, 5, 5, 5, 5, 5, 5};

    create_list_by_array(&head_1, &tail_1, array_1, 8);
    create_list_by_array(&head_2, &tail_2, array_2, 8);
    head_1 = sort(head_1, compare_int);
    tail_1 = get_tail(&head_1);

    ck_assert_int_eq(list_cmp(head_1, head_2, compare_int), 0);

    free_list(&head_1, &tail_1);
    free_list(&head_2, &tail_2);

    ck_assert_ptr_null(head_1);
    ck_assert_ptr_null(tail_1);
    ck_assert_ptr_null(head_2);
    ck_assert_ptr_null(tail_2);
}
END_TEST

START_TEST(test_sort_sorted_list)
{
    node_t *head_1 = NULL, *tail_1 = NULL;
    node_t *head_2 = NULL, *tail_2 = NULL;
    int array[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    create_list_by_array(&head_1, &tail_1, array, 11);
    create_list(&head_2, &tail_2, 11);
    head_1 = sort(head_1, compare_int);
    tail_1 = get_tail(&head_1);

    ck_assert_int_eq(list_cmp(head_1, head_2, compare_int), 0);

    free_list(&head_1, &tail_1);
    free_list(&head_2, &tail_2);

    ck_assert_ptr_null(head_1);
    ck_assert_ptr_null(tail_1);
    ck_assert_ptr_null(head_2);
    ck_assert_ptr_null(tail_2);
}
END_TEST

START_TEST(test_sort_reversed_list)
{
    node_t *head_1 = NULL, *tail_1 = NULL;
    node_t *head_2 = NULL, *tail_2 = NULL;
    int array[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};

    create_list_by_array(&head_1, &tail_1, array, 11);
    create_list(&head_2, &tail_2, 11);
    head_1 = sort(head_1, compare_int);
    tail_1 = get_tail(&head_1);

    ck_assert_int_eq(list_cmp(head_1, head_2, compare_int), 0);

    free_list(&head_1, &tail_1);
    free_list(&head_2, &tail_2);

    ck_assert_ptr_null(head_1);
    ck_assert_ptr_null(tail_1);
    ck_assert_ptr_null(head_2);
    ck_assert_ptr_null(tail_2);
}
END_TEST

START_TEST(test_sort_half_sorted_list)
{
    node_t *head_1 = NULL, *tail_1 = NULL;
    node_t *head_2 = NULL, *tail_2 = NULL;
    int array[] = {0, 1, 2, 3, 4, 5, 10, 9, 8, 7, 6};

    create_list_by_array(&head_1, &tail_1, array, 11);
    create_list(&head_2, &tail_2, 11);
    head_1 = sort(head_1, compare_int);
    tail_1 = get_tail(&head_1);

    ck_assert_int_eq(list_cmp(head_1, head_2, compare_int), 0);

    free_list(&head_1, &tail_1);
    free_list(&head_2, &tail_2);

    ck_assert_ptr_null(head_1);
    ck_assert_ptr_null(tail_1);
    ck_assert_ptr_null(head_2);
    ck_assert_ptr_null(tail_2);
}
END_TEST

START_TEST(test_sort_mix_list)
{
    node_t *head_1 = NULL, *tail_1 = NULL;
    node_t *head_2 = NULL, *tail_2 = NULL;
    int array_1[] = {7, 3, 10, 12, -4, 0, 5, -7, 1};
    int array_2[] = {-7, -4, 0, 1, 3, 5, 7, 10, 12};

    create_list_by_array(&head_1, &tail_1, array_1, 9);
    create_list_by_array(&head_2, &tail_2, array_2, 9);
    head_1 = sort(head_1, compare_int);
    tail_1 = get_tail(&head_1);

    ck_assert_int_eq(list_cmp(head_1, head_2, compare_int), 0);

    free_list(&head_1, &tail_1);
    free_list(&head_2, &tail_2);

    ck_assert_ptr_null(head_1);
    ck_assert_ptr_null(tail_1);
    ck_assert_ptr_null(head_2);
    ck_assert_ptr_null(tail_2);
}
END_TEST

START_TEST(test_sort_empty_list)
{
    node_t *head_1 = NULL, *tail_1 = NULL;

    head_1 = sort(head_1, compare_int);
    tail_1 = get_tail(&head_1);

    ck_assert_ptr_null(head_1);
    ck_assert_ptr_null(tail_1);
}
END_TEST

Suite* sort_suite(void)
{
    Suite *s;
    TCase *tc_pos;
    TCase *tc_neg;

    s = suite_create("sort:");

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_sort_one_elem_list);
    tcase_add_test(tc_pos, test_sort_equal_numbers_list);
    tcase_add_test(tc_pos, test_sort_sorted_list);
    tcase_add_test(tc_pos, test_sort_reversed_list);
    tcase_add_test(tc_pos, test_sort_half_sorted_list);
    tcase_add_test(tc_pos, test_sort_mix_list);
    suite_add_tcase(s, tc_pos);

    tc_neg = tcase_create("negatives");
    tcase_add_test(tc_neg, test_sort_empty_list);
    suite_add_tcase(s, tc_neg);

    return s;
}