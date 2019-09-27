import ctypes
import os

lib = ctypes.CDLL("func.dll")

_fib_arr = lib.fib_arr
_fib_arr.argtypes = (ctypes.POINTER(ctypes.c_int), ctypes.c_int)
_fib_arr.restype = ctypes.POINTER(ctypes.c_int)

def fib_arr(nums):
    src_len = len(nums)
    src = (ctypes.c_int * src_len)(*nums)
    _fib_arr(src, src_len)
    return src

_del_reps = lib.del_reps
_del_reps.argtypes = (ctypes.POINTER(ctypes.c_int), ctypes.c_int,
                      ctypes.POINTER(ctypes.c_int))
_del_reps.restype = ctypes.c_int

def del_reps(nums, nums_res):
    src_len = len(nums)
    res_len = len(nums_res)
    src = (ctypes.c_int * src_len)(*nums)
    res = (ctypes.c_int * res_len)(*nums_res)
    res_len = _del_reps(src, src_len, res)
    return res, res_len

n = int(input("Input length of array: "))
arr_1 = [0] * n
arr_1 = list(fib_arr(arr_1))
print(arr_1)

arr_2 = list(map(int, input("Input array (with spaces): ").split()))
new_array = [0] * len(arr_2)
new_array, res_len = del_reps(arr_2, new_array)
new_array = new_array[:res_len]
print (new_array)