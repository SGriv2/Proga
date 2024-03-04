#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include "IntVector.h"

IntVector *int_vector_new(size_t initial_capacity) // Создаёт массив нулевого размера.
{
    IntVector *struc = (IntVector *)malloc(sizeof(IntVector)); // Динамическое выделение памяти
    if (!struc)
    {
        return NULL;
    }
    struc->data = (int *)malloc(initial_capacity * sizeof(int));
    struc->capacity = initial_capacity;
    struc->size = 0;
    if (!struc->data)
    {
        free(struc);
        return NULL;
    }
    return struc;
}

IntVector *int_vector_copy(const IntVector *v)
{
    IntVector *t = malloc(sizeof(IntVector));
    if (t == NULL)
        return NULL;
    t->data = malloc(v->capacity * sizeof(int));
    if (t->data == NULL)
    {
        free(t);
        return NULL;
    }
    memcpy(t->data, v->data, sizeof(int) * v->capacity);
    t->size = v->size;
    t->capacity = v->capacity;
    return t;
}

void int_vector_free(IntVector *v) // Освобождает память, выделенную для вектора v
{
    free(v->data);
    free(v);
}

int int_vector_get_item(const IntVector *v, size_t index) // Выводит элемент под номером index
{
    if (index < v->capacity)
    {
        return v->data[index];
    }
    else
    {
        return -1;
    }
}

void int_vector_set_item(IntVector *v, size_t index, int item) // Присваивает элементу под номером index значение item
{
    if (index < v->capacity)
    {
        v->data[index] = item;
    }
    else
    {
        int counter = 1;
        int flag;
        flag = int_vector_reserve(v, (v->capacity) + counter);

        while (index + 1 != (v->capacity))
        {
            flag = int_vector_reserve(v, (v->capacity) + counter);
            counter++;
        }
        int_vector_resize(v, v->size + 1);
        v->data[index] = item;
    }
}

int int_vector_get_size(const IntVector *v) // Возвращает размер вектора
{
    return v->size;
}

int int_vector_get_capacity(const IntVector *v) // Возвращает ёмкость вектора
{
    return v->capacity;
}

int int_vector_push_back(IntVector *v, int item) // Добавляет элемент в конец массива
{
    if (v->capacity < v->size) // Если размер меньше ёмкости добавление элемента в конце массива
    {
        v->size++;
        v->data[v->capacity] = item;
    }
    else // Иначе ёмкость увеличивается в 2 раза
    {
        v->capacity *= 2;
        int *t = (int *)realloc(v->data, (size_t)v->capacity * sizeof(int));
        if (t == NULL) // Если произошла ошибка возвращает значение -1. 0 в случае успеха
        {
            return -1;
        }
        v->data = t;
        v->data[v->capacity - 1] = item;
        v->size++;
    }
    return 0;
}

void int_vector_pop_back(IntVector *v) // Удаляет последний элемент из массива
{
    if (v->data[v->capacity - 1] != 0)
    {
        v->data[v->capacity - 1] = 0;
    }
}

int int_vector_shrink_to_fit(IntVector *v) // Уменьшает емкость массива до его размера
{
    if (v->size < v->capacity)
    {
        v->capacity = v->size;
        int *t = (int *)realloc(v->data, v->size * sizeof(int));
        if (t == NULL)
            return -1;
        v->data = t;
        v->capacity = v->size;
        return 0;
    }
    return -1;
}

int int_vector_resize(IntVector *v, size_t new_size) // Изменяет емкость массива
{
    return v->size = new_size;
}

int int_vector_reserve(IntVector *v, size_t new_capacity) // Изменить размер массива
{
    if (new_capacity == v->capacity)
    {
        return 0;
    }
    if (new_capacity > v->capacity)
    {
        int *t = (int *)realloc(v->data, new_capacity * sizeof(int));
        if (t == NULL)
            return -1;
        v->data = t;
    }
    v->capacity = new_capacity;
    return 0;
}
