#include "sort.h"

void swap(uint32_t *arr, int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void bubbleSort(uint32_t *arr, int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(arr, j, j + 1);
}


void Quick_sort(uint32_t *arr, int low, int high)
{
    int i = low;
    int j = high;
    int pivot = arr[(low + high) / 2];

    do
    {
        while (arr[i] < pivot)
        {
            i++;
        }
        while (arr[j] > pivot)
        {
            j--;
        }
        if (i <= j)
        {
            if (arr[i] > arr[j])
            {
				swap(arr, i, j);
            }
            i++;
            if (j > 0)
            {
                j--;
            }
        }
    } while (i <= j);

    if (i < high)
    {
        Quick_sort(arr, i, high);
    }
    if (j > low)
    {
        Quick_sort(arr, low, j);
    }
}