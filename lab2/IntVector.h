#pragma once

typedef struct
{
    int *data;
    size_t size;
    size_t capacity;

} IntVector;

IntVector *int_vector_new(size_t initial_capacity);
void print_data(IntVector *vector);
void int_vector_free(IntVector *vector);
int vector_get_capacity(IntVector *vector);
int vector_get_size(IntVector *vector);
int vector_get_item(const IntVector *vector, size_t index);
void vector_set_item(IntVector *vector, size_t index, size_t element);
int int_vector_push_back(IntVector *vector, int element);
void int_vector_pop_back(IntVector *vector);
int int_vector_shrink_to_fit(IntVector *vector);
int int_vector_reserve(IntVector *vector, size_t new_capacity);
int int_vector_resize(IntVector *vector, size_t new_size);
IntVector *int_vector_copy(const IntVector *v);
