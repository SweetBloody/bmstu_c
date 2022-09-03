#include <stdio.h>
#include <string.h>
#include "my_strpbrk.h"
#include "my_strspn.h"

int main()
{
    int n, my_n;

    // Тесты my_strpbrk и strpbrk
    printf("Tests for strpbrk and my_strpbrk\n\n");

    //1
    printf("Test 1\nstr1: 'Hello world'\nstr2: 'folt'\n");
    if (!strpbrk("Hello world", "folt"))
        printf("strpbrk returned NULL\n");
    else
        printf("strpbrk: %s\n", strpbrk("Hello world", "folt"));
    if (!my_strpbrk("Hello world", "folt"))
        printf("my_strpbrk returned NULL\n");
    else
        printf("my_strpbrk: %s\n", my_strpbrk("Hello world", "folt"));
    printf("\n");

    //2
    printf("Test 2\nstr1: 'Hello world'\nstr2: 'frtk'\n");
    if (!strpbrk("Hello world", "frtk"))
        printf("strpbrk returned NULL\n");
    else
        printf("strpbrk: %s\n", strpbrk("Hello world", "frtk"));
    if (!my_strpbrk("Hello world", "frtk"))
        printf("my_strpbrk returned NULL\n");
    else
        printf("my_strpbrk: %s\n", my_strpbrk("Hello world", "frtk"));
    printf("\n");

    //3
    printf("Test 3\nstr1: 'Hello world'\nstr2: 'asfg'\n");
    if (!strpbrk("Hello world", "asfg"))
        printf("strpbrk returned NULL\n");
    else
        printf("strpbrk: %s\n", strpbrk("Hello world", "asfg"));
    if (!my_strpbrk("Hello world", "asfg"))
        printf("my_strpbrk returned NULL\n");
    else
        printf("my_strpbrk: %s\n", my_strpbrk("Hello world", "asfg"));
    printf("\n");

    //4
    printf("Test 4\nstr1: 'Hello world'\nstr2: ''\n");
    if (!strpbrk("Hello world", ""))
        printf("strpbrk returned NULL\n");
    else
        printf("strpbrk: %s\n", strpbrk("Hello world", ""));
    if (!my_strpbrk("Hello world", ""))
        printf("my_strpbrk returned NULL\n");
    else
        printf("my_strpbrk: %s\n", my_strpbrk("Hello world", ""));
    printf("\n");

    //5
    printf("Test 5\nstr1: ''\nstr2: 'world'\n");
    if (!strpbrk("", "world"))
        printf("strpbrk returned NULL\n");
    else
        printf("strpbrk: %s\n", strpbrk("", "world"));
    if (!my_strpbrk("", "world"))
        printf("my_strpbrk returned NULL\n");
    else
        printf("my_strpbrk: %s\n", my_strpbrk("", "world"));
    printf("\n");

    //6
    printf("Test 6\nstr1: ''\nstr2: ''\n");
    if (!strpbrk("", ""))
        printf("strpbrk returned NULL\n");
    else
        printf("strpbrk: %s\n", strpbrk("", ""));
    if (!my_strpbrk("", ""))
        printf("my_strpbrk returned NULL\n");
    else
        printf("my_strpbrk: %s\n", my_strpbrk("", ""));
    printf("\n");

    // Тесты my_strspn и strspn
    printf("Tests for strspn and my_strspn\n\n");

    //1
    printf("Test 1\nstr1: 'Hello world'\nstr2: 'eloH '\n");
    n = strspn("Hello world", "eloH ");
    my_n = my_strspn("Hello world", "eloH ");
    printf("strspn: %d\n", n);
    printf("my_strspn: %d\n", my_n);
    printf("\n");

    //2
    printf("Test 2\nstr1: 'Hello world'\nstr2: 'ewo Hr'\n");
    n = strspn("Hello world", "ewo Hr");
    my_n = my_strspn("Hello world", "ewo Hr");
    printf("strspn: %d\n", n);
    printf("my_strspn: %d\n", my_n);
    printf("\n");

    //3
    printf("Test 3\nstr1: 'Hello world'\nstr2: 'Hello world'\n");
    n = strspn("Hello world", "Hello world");
    my_n = my_strspn("Hello world", "Hello world");
    printf("strspn: %d\n", n);
    printf("my_strspn: %d\n", my_n);
    printf("\n");

    //4
    printf("Test 4\nstr1: 'Hello world'\nstr2: ''\n");
    n = strspn("Hello world", "");
    my_n = my_strspn("Hello world", "");
    printf("strspn: %d\n", n);
    printf("my_strspn: %d\n", my_n);
    printf("\n");

    //5
    printf("Test 5\nstr1: ''\nstr2: 'Hello world'\n");
    n = strspn("", "Hello world");
    my_n = my_strspn("", "Hello world");
    printf("strspn: %d\n", n);
    printf("my_strspn: %d\n", my_n);
    printf("\n");

    //6
    printf("Test 6\nstr1: ''\nstr2: ''\n");
    n = strspn("", "");
    my_n = my_strspn("", "");
    printf("strspn: %d\n", n);
    printf("my_strspn: %d\n", my_n);
    printf("\n");

    return 0;
}
