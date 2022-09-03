#include "book.h"
#include "const.h"
#include "cdio.h"
#include "string.h"

// Чтение структуры из файла
int read_book(FILE *f, char *title, int *num)
{
    int ch, number = 0;

    ch = read_string(f, title);

    if (ch == OK)
    {
        number += 1;

        ch = read_number(f, num);

        if (ch == OK)
            number += 1;
    }

    if (ch == STR_OVERFLOW)
        return STR_OVERFLOW;

    return number;
}

// Ввод данных (структур) списка из файла
int input_list_from_file_book(char *file_name, node_t **head, node_t **tail)
{
    FILE *file = fopen(file_name, "r");
    book_t *book = NULL;
    int ch = 2, year;
    char title[MAX_LEN];

    while (ch == 2)
    {
        book = malloc(sizeof(book_t));

        if (!book)
        {
            fclose(file);
            return MEMORY_GET_ERROR;
        }

        ch = read_book(file, title, &year);

        if (ch == 2)
        {
            strcpy(book->title, title);
            book->year = year;

            *tail = list_add(tail, book);

            if (!*head)
                *head = *tail;
        }
    }

    if (ch == STR_OVERFLOW)
    {
        fclose(file);
        return STR_OVERFLOW;
    }

    if (ch > 0)
    {
        fclose(file);
        return INCORRECT_INPUT;
    }

    if (!*head)
        return NO_DATA;

    return OK;
}

// Создание структуры книги по входным значениям полей
book_t *create_book(char *title, char *number)
{
    book_t *book = NULL;
    int year;

    year = atoi(number);

    if (year <= 0)
        return NULL;

    book = malloc(sizeof(book_t));
    if (!book)
        return NULL;

    strcpy(book->title, title);
    book->year = year;

    return book;
}

// Компаратор книг по году
int compare_book_year(const void *a, const void *b)
{
    return ((book_t*)a)->year - ((book_t*)b)->year;
}

// Компаратор книг
int compare_book(const void *a, const void *b)
{
    if (((book_t*)a)->year == ((book_t*)b)->year && strcmp(((book_t*)a)->title, ((book_t*)b)->title) == 0)
        return 0;
    else
        return 1;
}