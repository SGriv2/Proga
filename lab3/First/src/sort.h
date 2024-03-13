#ifndef SORT_H
#define SORT_H

#include <inttypes.h>

extern void merge_uint32(uint32_t *arr, int l, int m, int r);
extern void merge_sort_uint32(uint32_t *arr, int l, int r);
extern void merge_uint8(uint8_t *arr, int l, int m, int r);
extern void merge_sort_uint8(uint8_t *arr, int l, int r);

#endif
