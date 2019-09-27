#ifndef __MYSORT__H__
#define __MYSORT__H__

int compare_int(const void* p, const void* q);
void mysort(void* pa, void* pb, size_t size, int (*compar)(const void*, const void*));

#endif