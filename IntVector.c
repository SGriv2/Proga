#include <stdio.h>
#include "IntVector.h"
int main()
{
    IntVector *d_array = int_vector_new(3);
    printf("Ёмкость массива: %ld\n", d_array->capacity);
    if (d_array->data == NULL)
    {
        printf("Память не выделилась!!\n");
    }
    else
    {
        int_vector_set_item(d_array, 4, 5);
        printf("Ёмкость массива: %ld\n", d_array->capacity);
        for (int i = 0; i < d_array->capacity; i++)
        {
            printf("%d ", *(d_array->data + i));
        }
        printf("\n");

        printf("_________________________\n\n");

        int_vector_set_item(d_array, 6, 8);
        printf("Ёмкость массива: %ld\n", d_array->capacity);
        printf("Размер массива: %ld\n", d_array->size);
        for (int i = 0; i < d_array->capacity; i++)
        {
            printf("%d ", *(d_array->data + i));
        }
        printf("\n");
        int status = int_vector_get_item(d_array, 15);
        if (status == -1)
        {
            printf("Индекс вышел за пределы массива\n");
        }
        else
        {
            printf("Элемент - %d\n", status);
        }
        int_vector_push_back(d_array, 20);
        printf("\n");

        printf("_________________________\n\n");

        IntVector *t_array = int_vector_copy(d_array);
        printf("Ёмкость массива: %ld\n", t_array->capacity);
        printf("Размер массива: %ld\n", t_array->size);
        int_vector_set_item(t_array, 10, 25);
        for (int i = 0; i < t_array->capacity; i++)
        {
            printf("%d ", *(t_array->data + i));
        }
        printf("\n");

        printf("%d\n", int_vector_get_item(t_array, 6));

        printf("_________________________\n\n");

        int_vector_pop_back(t_array);
        for (int i = 0; i < t_array->capacity; i++)
        {
            printf("%d ", *(t_array->data + i));
        }
        printf("\n");

        printf("_________________________\n\n");

        int_vector_shrink_to_fit(t_array);

        int_vector_pop_back(t_array);
        for (int i = 0; i < t_array->capacity; i++)
        {
            printf("%d ", *(t_array->data + i));
        }
        printf("\n");

        for (int i = 0; i < d_array->capacity; i++)
        {
            printf("%d ", *(d_array->data + i));
        }
        printf("\n");

        printf("_________________________\n\n");

        int_vector_free(d_array);
        int_vector_free(t_array);
    }
    return 0;
}
