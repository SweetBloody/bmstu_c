#ifndef STRUCT_H

#define STRUCT_H

#include <stdint.h>
#define SURNAME_MAX 25 // Максимальная длина фамилии
#define NAME_MAX 10 // Максимальная длина имени
#define MARKS 4 // Количество оценок

struct student
{
    char surname[SURNAME_MAX + 1];
    char name[NAME_MAX + 1];
    unsigned int mark[MARKS];
};

#endif // STRUCT_H

