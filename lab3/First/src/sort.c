#include <stdlib.h>
#include <inttypes.h>
#include "./sort.h"

void merge_sort_uint32(uint32_t *arr, int l, int r)
{
    if (l < r)
    {

        int m = l + (r - l) / 2;

        merge_sort(arr, l, m);
        merge_sort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

void merge_uint32(uint32_t *arr, int l, int m, int r)
{
    int i, j, k;
    unsigned int n1 = m - l + 1;
    unsigned int n2 = r - m;
    uint32_t *L = (uint32_t *)malloc(n1 * sizeof(uint32_t));
    uint32_t *R = (uint32_t *)malloc(n2 * sizeof(uint32_t));

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void merge_sort_uint8(uint8_t *arr, int l, int r)
{
    if (l < r)
    {

        int m = l + (r - l) / 2;

        merge_sort_uint8(arr, l, m);
        merge_sort_uint8(arr, m + 1, r);

        merge_uint8(arr, l, m, r);
    }
}

void merge_uint8(uint8_t *arr, int l, int m, int r)
{
    int i, j, k;
    unsigned int n1 = m - l + 1;
    unsigned int n2 = r - m;
    uint8_t *L = (uint8_t *)malloc(n1 * sizeof(uint8_t));
    uint8_t *R = (uint8_t *)malloc(n2 * sizeof(uint8_t));

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}
