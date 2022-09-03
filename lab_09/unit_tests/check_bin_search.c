#include <check.h>
#include "process.h"
#include "cdio.h"
#include "check_bin_search.h"

// Тесты функции bin_search_title
START_TEST(test_search_title_begin)
{
    struct film *films = create_array(4);
    int index;

    film_init(&films[0], "Alone", "Home", 1234, 1, 1);
    film_init(&films[1], "Begin", "Nolan", 2018, 1, 1);
    film_init(&films[2], "PostMan", "Rob", 2006, 1, 1);
    film_init(&films[3], "Ufo", "Alex", 2002, 1, 1);

    index = bin_search_title("Alone", films, 4);

    free_array(films, 4);

    ck_assert_int_eq(index, 0);
}
END_TEST

START_TEST(test_search_title_end)
{
    struct film *films = create_array(4);
    int index;

    film_init(&films[0], "Alone", "Home", 1234, 1, 1);
    film_init(&films[1], "Begin", "Nolan", 2018, 1, 1);
    film_init(&films[2], "PostMan", "Rob", 2006, 1, 1);
    film_init(&films[3], "Ufo", "Alex", 2002, 1, 1);

    index = bin_search_title("Ufo", films, 4);

    free_array(films, 4);

    ck_assert_int_eq(index, 3);
}
END_TEST

START_TEST(test_search_title_mid)
{
    struct film *films = create_array(4);
    int index;

    film_init(&films[0], "Alone", "Home", 1234, 1, 1);
    film_init(&films[1], "Begin", "Nolan", 2018, 1, 1);
    film_init(&films[2], "PostMan", "Rob", 2006, 1, 1);
    film_init(&films[3], "Ufo", "Alex", 2002, 1, 1);

    index = bin_search_title("PostMan", films, 4);

    free_array(films, 4);

    ck_assert_int_eq(index, 2);
}
END_TEST

START_TEST(test_search_title_neg)
{
    struct film *films = create_array(4);
    int index;

    film_init(&films[0], "Alone", "Home", 1234, 1, 1);
    film_init(&films[1], "Begin", "Nolan", 2018, 1, 1);
    film_init(&films[2], "PostMan", "Rob", 2006, 1, 1);
    film_init(&films[3], "Ufo", "Alex", 2002, 1, 1);

    index = bin_search_title("Pop", films, 4);

    free_array(films, 4);

    ck_assert_int_eq(index, -1);
}
END_TEST

// Тесты функции bin_search_name
START_TEST(test_search_name_begin)
{
    struct film *films = create_array(4);
    int index;

    film_init(&films[0], "Ufo", "Alex", 2002, 1, 1);
    film_init(&films[1], "Alone", "Home", 1234, 1, 1);
    film_init(&films[2], "Begin", "Nolan", 2018, 1, 1);
    film_init(&films[3], "PostMan", "Rob", 2006, 1, 1);

    index = bin_search_name("Alex", films, 4);

    free_array(films, 4);

    ck_assert_int_eq(index, 0);
}
END_TEST

START_TEST(test_search_name_end)
{
    struct film *films = create_array(4);
    int index;

    film_init(&films[0], "Ufo", "Alex", 2002, 1, 1);
    film_init(&films[1], "Alone", "Home", 1234, 1, 1);
    film_init(&films[2], "Begin", "Nolan", 2018, 1, 1);
    film_init(&films[3], "PostMan", "Rob", 2006, 1, 1);

    index = bin_search_name("Rob", films, 4);

    free_array(films, 4);

    ck_assert_int_eq(index, 3);
}
END_TEST

START_TEST(test_search_name_mid)
{
    struct film *films = create_array(4);
    int index;

    film_init(&films[0], "Ufo", "Alex", 2002, 1, 1);
    film_init(&films[1], "Alone", "Home", 1234, 1, 1);
    film_init(&films[2], "Begin", "Nolan", 2018, 1, 1);
    film_init(&films[3], "PostMan", "Rob", 2006, 1, 1);

    index = bin_search_name("Home", films, 4);

    free_array(films, 4);

    ck_assert_int_eq(index, 1);
}
END_TEST

START_TEST(test_search_name_neg)
{
    struct film *films = create_array(4);
    int index;

    film_init(&films[0], "Ufo", "Alex", 2002, 1, 1);
    film_init(&films[1], "Alone", "Home", 1234, 1, 1);
    film_init(&films[2], "Begin", "Nolan", 2018, 1, 1);
    film_init(&films[3], "PostMan", "Rob", 2006, 1, 1);

    index = bin_search_name("Begin", films, 4);

    free_array(films, 4);

    ck_assert_int_eq(index, -1);
}
END_TEST

// Тесты функции bin_search_year
START_TEST(test_search_year_begin)
{
    struct film *films = create_array(4);
    int index;

    film_init(&films[0], "Alone", "Home", 1234, 1, 1);
    film_init(&films[1], "Ufo", "Alex", 2002, 1, 1);
    film_init(&films[2], "PostMan", "Rob", 2006, 1, 1);
    film_init(&films[3], "Begin", "Nolan", 2018, 1, 1);

    index = bin_search_year(1234, films, 4);

    free_array(films, 4);

    ck_assert_int_eq(index, 0);
}
END_TEST

START_TEST(test_search_year_end)
{
    struct film *films = create_array(4);
    int index;

    film_init(&films[0], "Alone", "Home", 1234, 1, 1);
    film_init(&films[1], "Ufo", "Alex", 2002, 1, 1);
    film_init(&films[2], "PostMan", "Rob", 2006, 1, 1);
    film_init(&films[3], "Begin", "Nolan", 2018, 1, 1);

    index = bin_search_year(2018, films, 4);

    free_array(films, 4);

    ck_assert_int_eq(index, 3);
}
END_TEST

START_TEST(test_search_year_mid)
{
    struct film *films = create_array(4);
    int index;

    film_init(&films[0], "Alone", "Home", 1234, 1, 1);
    film_init(&films[1], "Ufo", "Alex", 2002, 1, 1);
    film_init(&films[2], "PostMan", "Rob", 2006, 1, 1);
    film_init(&films[3], "Begin", "Nolan", 2018, 1, 1);

    index = bin_search_year(2006, films, 4);

    free_array(films, 4);

    ck_assert_int_eq(index, 2);
}
END_TEST

START_TEST(test_search_year_neg)
{
    struct film *films = create_array(4);
    int index;

    film_init(&films[0], "Alone", "Home", 1234, 1, 1);
    film_init(&films[1], "Ufo", "Alex", 2002, 1, 1);
    film_init(&films[2], "PostMan", "Rob", 2006, 1, 1);
    film_init(&films[3], "Begin", "Nolan", 2018, 1, 1);

    index = bin_search_year(2000, films, 4);

    free_array(films, 4);

    ck_assert_int_eq(index, -1);
}
END_TEST

Suite* bin_search_title_suite(void)
{
    Suite *s;
    TCase *tc_pos;
    TCase *tc_neg;

    s = suite_create("bin_search_title:");

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_search_title_begin);
    tcase_add_test(tc_pos, test_search_title_end);
    tcase_add_test(tc_pos, test_search_title_mid);
    suite_add_tcase(s, tc_pos);

    tc_neg = tcase_create("negatives");
    tcase_add_test(tc_neg, test_search_title_neg);
    suite_add_tcase(s, tc_neg);

    return s;
}

Suite* bin_search_name_suite(void)
{
    Suite *s;
    TCase *tc_pos;
    TCase *tc_neg;

    s = suite_create("bin_search_name:");

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_search_name_begin);
    tcase_add_test(tc_pos, test_search_name_end);
    tcase_add_test(tc_pos, test_search_name_mid);
    suite_add_tcase(s, tc_pos);

    tc_neg = tcase_create("negatives");
    tcase_add_test(tc_neg, test_search_name_neg);
    suite_add_tcase(s, tc_neg);

    return s;
}

Suite* bin_search_year_suite(void)
{
    Suite *s;
    TCase *tc_pos;
    TCase *tc_neg;

    s = suite_create("bin_search_year:");

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_search_year_begin);
    tcase_add_test(tc_pos, test_search_year_end);
    tcase_add_test(tc_pos, test_search_year_mid);
    suite_add_tcase(s, tc_pos);

    tc_neg = tcase_create("negatives");
    tcase_add_test(tc_neg, test_search_year_neg);
    suite_add_tcase(s, tc_neg);

    return s;
}