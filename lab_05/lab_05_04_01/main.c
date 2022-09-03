#include "const.h"

int main(int argc, char **argv)
{
    int ch, students_number;
    struct student students[100];

    if ((argc != 5 && argc != 3) || (strcmp(argv[1], "ft") != 0 && strcmp(argv[1], "dt") != 0))
    {
        printf("INCORRECT_ARGS\n");
        return INCORRECT_ARGS;
    }

    ch = file_check(argv);

    if (ch == FILE_OPEN_ERR)
    {
        printf("FILE_OPEN_ERR\n");
        return ch;
    }

    if (ch == FILE_ERR)
    {
        printf("FILE_ERR\n");
        return ch;
    }

    if (ch == FILE_CLOSE_ERR)
    {
        printf("FILE_CLOSE_ERR\n");
        return ch;
    }

    ch = read_file(argv, students, &students_number);

    if (ch == INCORRECT_INPUT)
    {
        printf("INCORRECT_INPUT\n");
        return ch;
    }

    if (ch == SURNAME_OVERFLOW)
    {
        printf("SURNAME_OVERFLOW\n");
        return ch;
    }

    if (ch == NAME_OVERFLOW)
    {
        printf("NAME_OVERFLOW\n");
        return ch;
    }

    if (ch == EMPTY_STR)
    {
        printf("EMPTY_STR\n");
        return ch;
    }

    if (argc == 5 && strcmp(argv[1], "ft") == 0)
    {
        struct student new_students[100];
        int new_number;

        ch = fit_surnames(students, students_number, new_students, &new_number, argv[4]);

        if (ch == NO_FIT_SURNAMES)
        {
            printf("NO_FIT_SURNAMES\n");
            return ch;
        }

        FILE *f = fopen(argv[3], "w");
        write_to_file(stdout, new_students, new_number);
        write_to_file(f, new_students, new_number);
        fclose(f);
    }
    else if (argc == 3 && strcmp(argv[1], "dt") == 0)
    {
        del_unfit_students(students, &students_number);
        FILE *f = fopen(argv[2], "w");
        write_to_file(stdout, students, students_number);
        write_to_file(f, students, students_number);
        fclose(f);
    }
    else
    {
        printf("INCORRECT_ARGS\n");
        return INCORRECT_ARGS;
    }

    return ch;
}
