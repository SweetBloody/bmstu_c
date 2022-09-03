#include "const.h"

// Проверка существования файла
int file_check(char **argv)
{
    FILE *f = fopen(argv[2], "r");

    if (f == NULL)
        return FILE_OPEN_ERR;

    if (ferror(f) != 0)
        return FILE_ERR;

    if (fclose(f) == EOF)
        return FILE_CLOSE_ERR;

    return OK;
}

// Функция создания и заполнения файла
int write_to_file(FILE *f, struct student *students, int num)
{
    for (int i = 0; i < num; i++)
    {
        fprintf(f, "%s\n%s\n", students[i].surname, students[i].name);
        fprintf(f, "%"PRIu32" %"PRIu32" %"PRIu32" %"PRIu32"\n", students[i].mark[0], students[i].mark[1], students[i].mark[2], students[i].mark[3]);
    }

    return OK;
}

// Функция чтения полей структуры из файла и составления массива структур
int read_file(char **argv, struct student *students, int *students_number)
{
    FILE *f = fopen(argv[2], "r");
    char surname[SURNAME_MAX + 1], name[NAME_MAX + 1];
    int ch, index = 0;

    ch = fscanf(f, "%s%s%"PRIu32"%"PRIu32"%"PRIu32"%"PRIu32"", surname, name, &students[index].mark[0], &students[index].mark[1], &students[index].mark[2], &students[index].mark[3]);

    if (ch == EOF)
    {
        fclose(f);
        return INCORRECT_INPUT;
    }

    while (ch == 6)
    {
        strncpy(students[index].surname, surname, SURNAME_MAX + 1);
        if (strlen(surname) > SURNAME_MAX)
        {
            fclose(f);
            return SURNAME_OVERFLOW;
        }

        strncpy(students[index].name, name, NAME_MAX + 1);
        if (strlen(name) > NAME_MAX)
        {
            fclose(f);
            return NAME_OVERFLOW;
        }

        index += 1;
        ch = fscanf(f, "%s%s%"PRIu32"%"PRIu32"%"PRIu32"%"PRIu32"", surname, name, &students[index].mark[0], &students[index].mark[1], &students[index].mark[2], &students[index].mark[3]);
    }

    if (ch > 0 && ch != 6)
    {
        fclose(f);
        return INCORRECT_INPUT;
    }


    *students_number = index;

    fclose(f);

    return OK;
}

// Функция вывода массива структур
void print_students(struct student *students, int num)
{
    for (int i = 0; i < num; i++)
    {
        printf("Surname: %s\n", students[i].surname);
        printf("Name: %s\n", students[i].name);

        printf("Marks:");
        for (int j = 0; j < MARKS; j++)
            printf(" %d", students[i].mark[j]);
        printf("\n");
    }
}
