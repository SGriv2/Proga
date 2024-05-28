#include "support_lib.h"
#include "sort.h"

double wtime()
{
    struct timeval t;
    gettimeofday(&t, NULL);
    return (double)t.tv_sec + (double)t.tv_usec * 1E-6;
}

void random_el(uint32_t *arr, unsigned int n)
{
    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 100000;
    }
}

void sama_zap()
{
  unsigned int n;
  printf("Введите размер массива:");
  scanf("%d", &n);
  printf("\n");

  uint32_t *arr = (uint32_t *)malloc(n * sizeof(int));

  printf("Вводите данные по очередно:\n");

  for(int i = 0; i < n; i++)
  {
    scanf("%d", &arr[i]);
  }

  int tmp;
  printf("Выберите способ сортировки\n");
  printf("1 - Сортировка пузырьком\n2 - Быстрая сортировка\n");
  scanf("%d", &tmp);

  switch (tmp)
  {
  case 1:
    bubbleSort(arr, n);
    break;
  
  case 2:
    Quick_sort(arr, 0, n);
    break;
  default:
    printf("Неправильные данные\n");
    break;
  }
}

void auto_zap()
{
  printf("Сортировка пузырьком\n");

  for (int i = 8; i <= 15; i++)
  {
    unsigned int n = pow(2, i);
    uint32_t *arr;
    arr = (uint32_t *)malloc(n * sizeof(int));
    random_el(arr, n);

    double start_time = wtime();

    bubbleSort(arr, n);

    printf("Время сортировки %d элементов: %f\n", n, wtime() - start_time);
  }

  printf("Быстрая сортировка\n");

  for (int i = 8; i <= 15; i++)
  {
    unsigned int n = pow(2, i);
    uint32_t *arr;
    arr = (uint32_t *)malloc(n * sizeof(int));
    random_el(arr, n);

    double start_time = wtime();

    Quick_sort(arr, 0, n);

    printf("Время сортировки %d элементов: %f\n", n, wtime() - start_time);
  }
}