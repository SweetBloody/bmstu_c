#ifndef C_PROCESS_H

#define C_PROCESS_H

#include "const.h"

float file_avg_mark(struct student *students, int num); // Нахождение средней оценки по файлу

float student_avg_mark(struct student student); // Нахождение средней оценки студента

void del_unfit_students(struct student *students, int *num); // Удаление студентов, чей средний балл меньше среднего балла по файлу

#endif // C_PROCESS_H
