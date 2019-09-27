#ifndef __MYSORT__H__
#define __MYSORT__H__

#ifdef EXPORTS
#define MYSORT_DLL __declspec(dllexport)
#else
#define MYSORT_DLL __declspec(dllimport)
#endif

#define MYSORT_DECL __cdecl

MYSORT_DLL void MYSORT_DECL mysort (void* pa, void* pb, size_t size, int (*compar)(const void*, const void*));
MYSORT_DLL int MYSORT_DECL compare_int(const void* p, const void* q);

#endif