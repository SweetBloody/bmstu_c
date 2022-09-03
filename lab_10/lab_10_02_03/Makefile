## Компилятор
CC := gcc

## Расположение исходных файлов
SRC := src

## Расположение исходных файлов для юнит тестов
UNITS := unit_tests

## Расположение объектных файлов
OUT := out

## Расположение заголовочных файлов
INC := inc

## Флаги компиляции
CFLAGS := -std=c99 -Wall -Werror -pedantic -ggdb -I inc

## Общие объектные файлы программы
OBJS_MAIN := $(OUT)/cdio.o $(OUT)/node.o $(OUT)/process.o

## Общие объектные файлы юнит тестов
OBJS_UNITS := $(OUT)/check_sqr.o $(OUT)/check_multiply.o $(OUT)/check_division.o

app.exe : $(OUT)/main.o $(OBJS_MAIN)
		$(CC) -o $@ $^

unit_tests.exe : $(OUT)/check_main.o $(OBJS_MAIN) $(OBJS_UNITS)
		$(CC) -o $@ $^ -lcheck

$(OUT)/%.o : $(SRC)/%.c
		mkdir -p $(OUT)
		$(CC) $(CFLAGS) -c $^ -o $@

$(OUT)/%.o : $(UNITS)/%.c
		mkdir -p $(OUT)
		$(CC) $(CFLAGS) -c $^ -lcheck -o $@

.PHONY : clean
clean :
	rm $(OUT)/*.o *.exe