## Компилятор
CC := gcc

## Флаги компиляции
CFLAGS := -std=c99 -Wall -Werror -pedantic -Wextra -Wfloat-equal -Wfloat-conversion -ggdb

## Общие объектные файлы программы
OBJS_MAIN := cdio.o file_process.o process.o

## Общие объектные файлы юнит тестов
OBJS_UNITS := check_mysort.o check_key.o process.o

app.exe : main.o $(OBJS_MAIN)
	$(CC) -o $@ $^

unit_tests.exe : check_main.o $(OBJS_UNITS)
	$(CC) -o $@ $^ -lcheck

main.o : src/main.c
	$(CC) $(CFLAGS) -c $^ -o $@

cdio.o : src/cdio.c inc/cdio.h
	$(CC) $(CFLAGS) -c src/cdio.c -o $@

file_process.o : src/file_process.c inc/file_process.h
	$(CC) $(CFLAGS) -c src/file_process.c -o $@

process.o : src/process.c inc/process.h
	$(CC) $(CFLAGS) -c src/process.c -o $@

check_main.o : unit_tests/check_main.c
	$(CC) $(CFLAGS) -c $^ -lcheck -o $@

check_mysort.o : unit_tests/check_mysort.c inc/check_mysort.h
	$(CC) $(CFLAGS) -c unit_tests/check_mysort.c -lcheck -o $@

check_key.o : unit_tests/check_key.c inc/check_key.h
	$(CC) $(CFLAGS) -c unit_tests/check_key.c -lcheck -o $@

.PHONY : clean
clean :
	rm *.o *.exe