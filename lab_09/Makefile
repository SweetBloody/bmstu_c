## Компилятор
CC := gcc

## Флаги компиляции
CFLAGS := -std=gnu99 -Wall -Werror -pedantic -ggdb -I inc

## Общие объектные файлы программы
OBJS_MAIN := out/cdio.o out/file_process.o out/process.o

## Общие объектные файлы юнит тестов
OBJS_UNITS := out/check_bin_search.o out/process.o out/cdio.o

app.exe : out/main.o $(OBJS_MAIN)
	$(CC) -o $@ $^

unit_tests.exe : out/check_main.o $(OBJS_UNITS)
	$(CC) -o $@ $^ -lcheck

out/main.o : src/main.c
	mkdir -p out
	$(CC) $(CFLAGS) -c $^ -o $@

out/cdio.o : src/cdio.c inc/cdio.h
	mkdir -p out
	$(CC) $(CFLAGS) -c src/cdio.c -o $@

out/file_process.o : src/file_process.c inc/file_process.h
	mkdir -p out
	$(CC) $(CFLAGS) -c src/file_process.c -o $@

out/process.o : src/process.c inc/process.h
	mkdir -p out
	$(CC) $(CFLAGS) -c src/process.c -o $@

out/check_main.o : unit_tests/check_main.c
	mkdir -p out
	$(CC) $(CFLAGS) -c $^ -lcheck -o $@

out/check_bin_search.o : unit_tests/check_bin_search.c inc/check_bin_search.h
	mkdir -p out
	$(CC) $(CFLAGS) -c unit_tests/check_bin_search.c -lcheck -o $@

.PHONY : clean
clean :
	rm out/*.o *.exe