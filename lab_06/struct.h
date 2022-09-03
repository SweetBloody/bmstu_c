#ifndef STRUCT_H
#define STRUCT_H

#include "const.h"

#define TITLE_MAX 25 // Максимальная длина названия
#define NAME_MAX 25 // Максимальная длина фамилии

struct film
{
    char title[TITLE_MAX + 1];
    char name[NAME_MAX + 1];
    int year;
};

#endif // STRUCT_H
