#include <stdlib.h>
#include <stdarg.h>
#include <math.h>
#include "my_func.h"

// Перевод числа из десятичной в восьмеричную и запись в строку
static void oct_to_string(char *string, unsigned int number, int *count, int *index, size_t n)
{
    int ost = number % 8;

    number /= 8;

    if (number > 0)
        oct_to_string(string, number, count, index, n);

    if (*index < n - 1 && n != 0)
    {
        string[*index] = (char) ('0' + ost);
        (*index)++;
    }

    (*count)++;
}

int my_snprintf(char *buf, size_t n, const char *format, ...)
{
    va_list vl;
    int count = 0, index = 0;

    va_start(vl, format);

    while (*format != '\0')
    {
        if (*format == '%' && *(format + 1) == 's')
        {
            char *str = va_arg(vl, char*);

            while (*str != '\0')
            {
                if (index != n - 1 && n != 0)
                {
                    buf[index] = *str;
                    index++;
                }

                str++;
                count++;
            }

            format++;
        }
        else if (*format == '%' && *(format + 1) == 'o')
        {
            int num = va_arg(vl, int);

            oct_to_string(buf, (unsigned int) num, &count, &index, n);
            format++;
        }
        else
        {
            if (index != n - 1 && n != 0)
            {
                buf[index] = *format;
                index++;
            }

            count++;
        }

        format++;
    }

    if (buf != NULL)
        buf[index] = '\0';

    return count;
}