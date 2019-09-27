#ifndef __FUNC__LIB__H
#define __FUNC__LIB__H

#include <stdio.h>

#ifdef EXPORTS
#define FUNC_DLL __declspec(dllexport)
#else
#define FUNC_DLL __declspec(dllimport)
#endif

#define FUNC_DECL __cdecl

FUNC_DLL int* FUNC_DECL fib_arr(int *array, int n);
FUNC_DLL int FUNC_DECL del_reps(const int *array, int n, int *new_array);

#endif