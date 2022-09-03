#include "const.h"

// Нахождение средней оценки по файлу
float file_avg_mark(struct student *students, int num)
{
    float avg = 0;

    for (int i = 0; i < num; i++)
        for (int j = 0; j < MARKS; j++)
            avg += students[i].mark[j];

    avg = avg / (num * MARKS);

    return avg;
}

// Нахождение средней оценки студента
float student_avg_mark(struct student student)
{
    float avg = 0;

    for (int i = 0; i < MARKS; i++)
        avg += student.mark[i];

    avg = avg / MARKS;

    return avg;
}

// Удаление студентов, чей средний балл меньше среднего балла по файлу
void del_unfit_students(struct student *students, int *num)
{
    float avg = file_avg_mark(students, *num);

    for (int i = 0; i < *num; i++)
    {
        if (student_avg_mark(students[i]) < avg)
        {
            for (int j = i; j < *num - 1; j++)
                students[j] = students[j + 1];

            *num -= 1;
            i -= 1;
        }
    }
}
