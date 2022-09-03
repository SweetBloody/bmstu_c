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

## Расположение библиотечных файлов
LIBS := libs

## Флаги компиляции
CFLAGS := -std=c99 -Wall -Werror -pedantic -ggdb -Iinc

## Система
SYS := -Wl,--subsystem,windows

## Файлы библиотек
LIB_FILES := process.dll

## Общие объектные файлы юнит тестов
OBJS_UNITS := $(OUT)/check_fib.o $(OUT)/check_single.o

unit_tests : unit_tests.exe
lib : $(LIBS)/process.dll

unit_tests.exe : $(OUT)/check_main.o $(OUT)/process.o $(OBJS_UNITS)
		$(CC) -o $@ $^ -lcheck

$(OUT)/%.o : $(SRC)/%.c
		mkdir -p $(OUT)
		$(CC) $(CFLAGS) -c $^ -o $@

$(OUT)/%.o : $(UNITS)/%.c
		mkdir -p $(OUT)
		$(CC) $(CFLAGS) -c $^ -lcheck -o $@

$(LIBS)/process.dll : $(OUT)/process.o
		mkdir -p $(LIBS)
		$(CC) -shared $^ $(SYS) -o $@

.PHONY : clean
clean :
	rm $(OUT)/*.o $(LIBS)/*.dll *.exe