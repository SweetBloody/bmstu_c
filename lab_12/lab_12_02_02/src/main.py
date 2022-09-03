import ctypes

lib = ctypes.CDLL('../libs/process.dll')

# int fib_array(int *array, int size)
fib_array = lib.fib_array
fib_array.argtypes = (ctypes.POINTER(ctypes.c_int), ctypes.c_int)
fib_array.restype = ctypes.c_int


def fibArray(size):
    if size <= 0:
        print("Incorrect size\n")
    array = (ctypes.c_int * size)()
    ch = fib_array(array, size)
    if ch != 0:
        print("Error\n")
    return list(array)


# int single_elems_array(int *src_arr, int src_arr_size, int *dst_arr, int *dst_arr_size)
single_elems_array = lib.single_elems_array
single_elems_array.argtypes = (ctypes.POINTER(ctypes.c_int), ctypes.c_int,
                             ctypes.POINTER(ctypes.c_int), ctypes.POINTER(ctypes.c_int))
single_elems_array.restype = ctypes.c_int


def maxSizeArray(array):
    srcArray = (ctypes.c_int * int(len(array)))(*array)
    dstArray = (ctypes.c_int * int(len(array)))()
    dstLen = ctypes.c_int(len(array))
    ch = single_elems_array(srcArray, len(srcArray), dstArray, dstLen)
    if ch != 0:
        print("Error\n")
    return list(dstArray), dstLen.value


def neededSizeArray(array):
    srcArray = (ctypes.c_int * int(len(array)))(*array)
    dstLen = ctypes.c_int(0)
    ch = single_elems_array(srcArray, len(srcArray), None, dstLen)
    dstArray = (ctypes.c_int * int(dstLen.value))()
    ch = single_elems_array(srcArray, len(srcArray), dstArray, dstLen)
    if ch != 0:
        print("Error\n")
    return list(dstArray), dstLen.value


def input_number(message):
    number = input(message)
    try:
        number = int(number)
    except ValueError:
        print("Введите число!\n")
    return number


choice = -1
while choice:
    print("|------------------------------------|")
    print("| 1 - Create fib array               |")
    print("| 2 - Array of single elems          |")
    print("| 0 - Exit                           |")
    print("|------------------------------------|")
    choice = input_number(">")
    if choice == 1:
        size = input_number("Input the size for fib array:\n")
        print(fibArray(size))
    if choice == 2:
        choice_2 = -1
        while choice_2:
            print("|------------------------------------|")
            print("| 1 - Max length                     |")
            print("| 2 - Needed length                  |")
            print("| 0 - Exit                           |")
            print("|------------------------------------|")
            choice_2 = input_number(">")
            if choice_2 == 1:
                array = list(map(int, input("Input array:\n").split()))
                dstArray, dstLen = maxSizeArray(array)
                print(dstArray)
                print("Max length = {0}\nNeeded length = {1}".format(len(array), dstLen))
            if choice_2 == 2:
                array = list(map(int, input("Input array:\n").split()))
                dstArray, dstLen = neededSizeArray(array)
                print(dstArray)
                print("Needed length = {0}".format(dstLen))
