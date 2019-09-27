#ifndef __KEY__H__
#define __KEY__H__

#ifdef EXPORTS
#define KEY_DLL __declspec(dllexport)
#else
#define KEY_DLL __declspec(dllimport)
#endif

#define KEY_DECL __cdecl

KEY_DLL float KEY_DECL average(const int *pa, const int *pb);
KEY_DLL int KEY_DECL newArraySize(const int *pa, const int *pb, int average);
KEY_DLL void KEY_DECL newArray(const int *pb_src, const int *pe_src, int **pb_dst, int **pe_dst, float average);
KEY_DLL int KEY_DECL key(const int *pb_src, const int *pe_src, int **pb_dst, int **pe_dst);

#endif