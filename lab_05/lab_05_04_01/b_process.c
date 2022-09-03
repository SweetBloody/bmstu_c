#include "const.h"

// Функция поиска студентов с подходящей фамилией
int fit_surnames(struct student *students, int num, struct student *new_students, int *new_num, char *str)
{
    int len = strlen(str), index = 0;

    for (int i = 0; i < num; i++)
    {
        if (strncmp(students[i].surname, str, len) == 0)
        {
            new_students[index] = students[i];
            index += 1;
        }
    }

    *new_num = index;

    if (index == 0)
        return NO_FIT_SURNAMES;
    else
        return OK;
}
