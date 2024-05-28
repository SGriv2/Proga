#include <stdio.h>
#include <stdlib.h>
#include "IntVector.h"

IntVector *int_vector_new(size_t initial_capacity)
{
    IntVector *vector = (IntVector *)malloc(sizeof(IntVector));
    if (!vector)
    {
        free(vector);
        return NULL;
    }
    else
    {
        vector->data = (int *)malloc(sizeof(int) * initial_capacity);
        vector->capacity = initial_capacity;
        vector->size = 0;
        if (!vector->data)
        {
            free(vector->data);
            free(vector);
            return NULL;
        }
        return vector;
    }
}

void int_vector_free(IntVector *vector)
{
    free(vector->data); 
    free(vector);
}

int vector_get_size(IntVector *vector)
{
    return vector->size;
}

int vector_get_capacity(IntVector *vector)
{
    return vector->capacity;
}

int vector_get_item(const IntVector *vector, size_t index)
{
    if (index < vector->capacity)
    {
        return (vector->data)[index];
    }
    else
    {
        return -1;
    }
}

void vector_set_item(IntVector *vector, size_t index, size_t element)
{
    if (index < vector->capacity && vector->data[index] == 0)
    {
        vector->data[index] = element;
        vector->size += 1;
    }
}

int int_vector_push_back(IntVector *vector, int element)
{
    if (vector->size < vector->capacity)
    {
        vector->data[vector->size] = element;
        vector->size += 1;
    }
    else
    {
        vector->capacity *= 2;
        int *new_data = (int *)realloc(vector->data, (size_t)vector->capacity * sizeof(int));
        if (!new_data)
        {
            free(new_data);
            return -1;
        }
        vector->data = new_data;
        vector->size += 1;
        vector->data[vector->capacity / 2] = element;
    }
    return 0;
}

void int_vector_pop_back(IntVector *vector)
{
    if (vector->size != 0)
    {
        vector->data[vector->size - 1] = 0;
        vector->size -= 1;
    }
}

int int_vector_shrink_to_fit(IntVector *vector)
{
    if (vector->size < vector->capacity)
    {
        vector->capacity = vector->size;
        int *t = (int *)realloc(vector->data, vector->size * sizeof(int));
        if (t == NULL)
        {
            return -1;
        }
        vector->data = t;
        return 0;
    }
    return -1;
}

int int_vector_reserve(IntVector *vector, size_t new_capacity)
{
    if (new_capacity > vector->capacity)
    {
        vector->capacity = new_capacity;
        int *t = (int *)realloc(vector->data, (size_t)vector->capacity * sizeof(int));
        if (t == NULL)
        {
            return -1;
        }
        vector->data = t;
        return 0;
    }
    return -1;
}

int int_vector_resize(IntVector *vector, size_t new_size)
{
    if (new_size == vector->size)
    {
        return 0;
    }
    if (new_size > vector->size)
    {
        int *t = (int *)realloc(vector->data, new_size * sizeof(int));
        if (t == NULL)
            return -1;
        vector->data = t;

        for (size_t i = new_size - vector->size; i < new_size; i++)
            vector->data[i] = 0;
    }
    vector->size = new_size;
    vector->capacity = new_size;
    return 0;
}

IntVector *int_vector_copy(const IntVector *vector)
{
    IntVector *copy = int_vector_new(vector->capacity);
    if (!copy)
    {
        free(copy);
        return NULL;
    }
    for (size_t i = 0; i < vector->capacity; i++)
    {
        copy->data[i] = vector->data[i];
    }
    return copy;
}

void print_data(IntVector *vector)
{
    for(int i =0; i < vector->capacity; i++)
    {
        printf("%d ", vector->data[i]);
    }
    printf("\n");
}