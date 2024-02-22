#include <stdio.h>
#include "IntVector.h"
int main()
{
    IntVector *d_array = int_vector_new(1);
    int_vector_set_item(d_array, 0, 12);
    printf("Индекс: %d\n", int_vector_get_item(d_array, 0));
    printf("Ёмкость массива: %d\n", int_vector_get_capacity(d_array));
    int_vector_push_back(d_array, 11);
    printf("Индекс: %d\n", int_vector_get_item(d_array, 1));
    printf("Размер массива: %d\n", int_vector_get_size(d_array));
    printf("Ёмкость массива: %d\n", int_vector_get_capacity(d_array));
    int_vector_push_back(d_array, 35);
    printf("Размер массива: %d\n", int_vector_get_size(d_array));
    printf("Индекс: %d\n", int_vector_get_item(d_array, 1));
    printf("Ёмкость массива: %d\n", int_vector_get_capacity(d_array));
    int_vector_pop_back(d_array);
    int_vector_shrink_to_fit(d_array);
    printf("Размер массива: %d\n", int_vector_get_size(d_array));
    printf("Ёмкость массива: %d\n", int_vector_get_capacity(d_array));
    int_vector_resize(d_array, 10);
    printf("Размер массива: %d\n", int_vector_get_size(d_array));
    printf("Ёмкость массива: %d\n", int_vector_get_capacity(d_array));
    int_vector_reserve(d_array, 15);
    printf("Размер массива: %d\n", int_vector_get_size(d_array));
    printf("Ёмкость массива: %d\n", int_vector_get_capacity(d_array));
    int_vector_free(d_array);
    return 0;
}
