#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INIT_SIZE 16

typedef struct IntVector
{
    int *Vector;
    size_t size;
    size_t capacity;
} IntVector;

IntVector *int_Vector_new(size_t initial_capacity)
{
    IntVector *NewVector = malloc(sizeof(IntVector));

    if (NewVector == NULL)
    {
        return NULL;
    }
    NewVector->Vector = malloc(initial_capacity * sizeof(int));

    if (NewVector->Vector == NULL)
    {
        return NULL;
    }
    NewVector->size = 0;
    NewVector->capacity = initial_capacity;
    return NewVector;
}

IntVector *int_vector_copy(const IntVector *v)
{
    IntVector *new = malloc(sizeof(IntVector));
    if (new == NULL)
    {
        return NULL;
    }
    new->Vector = malloc(v->size * sizeof(int));
    if (new->Vector == NULL)
    {
        return NULL;
    }
    for (int i = 0; i < v->size; i++)
    {
        (new->Vector)[i] = (v->Vector)[i];
    }
    new->capacity = v->capacity;

    return new;
}

void *init_vector(int *Vector, size_t *length, size_t *capacity, int value)
{
    if (*length >= *capacity)
    {
        (*capacity) *= 2;
        int *ar = malloc(sizeof(int));
        if (ar == NULL)
        {
            return Vector;
        }
        for (int i = 0; i < *length; i++)
        {
            ar[i] = Vector[i];
        }
        free(Vector);
        Vector = ar;
    }
    Vector[*length] = value;
    (*length)++;

    return Vector;
}

void int_vector_free(IntVector *v)
{
    free(v->Vector);
    v->size = v->capacity = 0;
}

int main()
{

    IntVector *first = int_Vector_new(INIT_SIZE);
    for (int i = 0; i < 16; i++)
    {
        first->Vector = init_vector(first->Vector, &first->size, &first->capacity, rand() % 40 - 20);
    }
    IntVector *second = int_vector_copy(first);
    for (int i = 0; i < first->capacity; i++)
    {
        printf("%d ", first->Vector[i]);
    }

    printf("\n");

    for (int i = 0; i < first->capacity; i++)
    {
        printf("%d ", second->Vector[i]);
    }
    printf("\n");

    int_vector_free(first);
    int_vector_free(second);

    return 0;
}
