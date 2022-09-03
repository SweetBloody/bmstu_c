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

## Директория со статической библиотекой
STATIC := static

## Директория со динамической библиотекой (динамическая компановка)
DIN_1 := din_1

## Директория со динамической библиотекой (динамическая загрузка)
DIN_2 := din_2

## Флаги компиляции
CFLAGS := -std=c99 -Wall -Werror -pedantic -ggdb

################# СТАТИЧЕСКАЯ БИБЛИОТЕКА #################

## Общие объектные файлы программы
OBJS_MAIN_STATIC := $(STATIC)/$(OUT)/file_process.o

## Файлы библиотек
LIB_FILES_STATIC := $(STATIC)/$(LIBS)/libcdio.a $(STATIC)/$(LIBS)/libprocess.a

## Общие объектные файлы юнит тестов
OBJS_UNITS_STATIC := $(STATIC)/$(OUT)/check_key.o $(STATIC)/$(OUT)/check_mysort.o

static : app_static.exe
unit_tests_static : unit_tests_static.exe

app_static.exe : $(STATIC)/$(OUT)/main.o $(OBJS_MAIN_STATIC) $(LIB_FILES_STATIC)
		$(CC) -o $@ $^

unit_tests_static.exe : $(STATIC)/$(OUT)/check_main.o $(OBJS_MAIN_STATIC) $(OBJS_UNITS_STATIC) $(LIB_FILES_STATIC)
		$(CC) -o $@ $^ -lcheck

$(STATIC)/$(OUT)/%.o : $(STATIC)/$(SRC)/%.c
		mkdir -p $(STATIC)/$(OUT)
		$(CC) $(CFLAGS) -I$(STATIC)/inc -c $^ -o $@

$(STATIC)/$(OUT)/%.o : $(STATIC)/$(UNITS)/%.c
		mkdir -p $(STATIC)/$(OUT)
		$(CC) $(CFLAGS) -I$(STATIC)/inc -c $^ -lcheck -o $@

$(STATIC)/$(LIBS)/libcdio.a : $(STATIC)/$(OUT)/cdio.o
		mkdir -p $(STATIC)/$(LIBS)
		ar cr $@ $^

$(STATIC)/$(LIBS)/libprocess.a : $(STATIC)/$(OUT)/process.o
		mkdir -p $(STATIC)/$(LIBS)
		ar cr $@ $^
##########################################################


################# ДИНАМИЧЕСКАЯ БИБЛИОТЕКА 1 #################

## Система
SYS := -Wl,--subsystem,windows

## Общие объектные файлы программы
OBJS_MAIN_DIN_1 := $(DIN_1)/$(OUT)/file_process.o

## Файлы библиотек
LIB_FILES_DIN_1 := cdio_1.dll process_1.dll

## Общие объектные файлы юнит тестов
OBJS_UNITS_DIN_1 := $(DIN_1)/$(OUT)/check_key.o $(DIN_1)/$(OUT)/check_mysort.o

din_1 : app_din_1.exe
unit_tests_din_1 : unit_tests_din_1.exe

app_din_1.exe : $(DIN_1)/$(OUT)/main.o $(OBJS_MAIN_DIN_1) $(LIB_FILES_DIN_1)
		$(CC) -o $@ $^

unit_tests_din_1.exe : $(DIN_1)/$(OUT)/check_main.o $(OBJS_MAIN_DIN_1) $(OBJS_UNITS_DIN_1) $(LIB_FILES_DIN_1)
		$(CC) -o $@ $^ -lcheck

$(DIN_1)/$(OUT)/%.o : $(DIN_1)/$(SRC)/%.c
		mkdir -p $(DIN_1)/$(OUT)
		$(CC) $(CFLAGS) -I$(DIN_1)/inc -D ARR_EXPORTS -c $^ -o $@

$(DIN_1)/$(OUT)/%.o : $(DIN_1)/$(UNITS)/%.c
		mkdir -p $(DIN_1)/$(OUT)
		$(CC) $(CFLAGS) -I$(DIN_1)/inc -c $^ -lcheck -o $@

cdio_1.dll : $(DIN_1)/$(OUT)/cdio.o
		$(CC) -shared $^ $(SYS) -o $@

process_1.dll : $(DIN_1)/$(OUT)/process.o
		$(CC) -shared $^ $(SYS) -o $@
#############################################################

################# ДИНАМИЧЕСКАЯ БИБЛИОТЕКА 2 #################

## Общие объектные файлы программы
OBJS_MAIN_DIN_2 := $(DIN_2)/$(OUT)/file_process.o

## Файлы библиотек
LIB_FILES_DIN_2 := cdio_2.dll process_2.dll

## Общие объектные файлы юнит тестов
OBJS_UNITS_DIN_2 := $(DIN_2)/$(OUT)/check_key.o $(DIN_2)/$(OUT)/check_mysort.o

din_2 : app_din_2.exe cdio_2.dll process_2.dll
unit_tests_din_2 : unit_tests_din_2.exe

app_din_2.exe : $(DIN_2)/$(OUT)/main.o $(OBJS_MAIN_DIN_2)
		$(CC) -o $@ $^

unit_tests_din_2.exe : $(DIN_2)/$(OUT)/check_main.o $(OBJS_MAIN_DIN_2) $(OBJS_UNITS_DIN_2) $(LIB_FILES_DIN_2)
		$(CC) -o $@ $^ -lcheck

$(DIN_2)/$(OUT)/%.o : $(DIN_2)/$(SRC)/%.c
		mkdir -p $(DIN_2)/$(OUT)
		$(CC) $(CFLAGS) -I$(DIN_2)/inc -D ARR_EXPORTS -c $^ -o $@

$(DIN_2)/$(OUT)/%.o : $(DIN_2)/$(UNITS)/%.c
		mkdir -p $(DIN_2)/$(OUT)
		$(CC) $(CFLAGS) -I$(DIN_2)/inc -c $^ -lcheck -o $@

cdio_2.dll : $(DIN_2)/$(OUT)/cdio.o
		$(CC) -shared $^ $(SYS) -o $@

process_2.dll : $(DIN_2)/$(OUT)/process.o
		$(CC) -shared $^ $(SYS) -o $@
#############################################################

.PHONY : clean static unit_tests_static din_1 unit_tests_din_1 din_2 unit_tests_din_2
clean :
	rm $(STATIC)/$(OUT)/*.o $(STATIC)/$(LIBS)/*.a $(DIN_1)/$(OUT)/*.o *.dll $(DIN_2)/$(OUT)/*.o *.exe