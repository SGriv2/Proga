#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>
#include <stdint.h>
#include <math.h>
#include "sort_lib/sort.h"
#include "sort_lib/support_lib.h"

int main()
{
  int tmp;

  printf("Выберите способ заполнения массива\n");
  printf("1 - Заполните массив самостоятельно\n2 - массив заполнится автоматитечески\n");
  scanf("%d", &tmp);

  switch (tmp)
  {
  case 1:
    sama_zap();
    break;
  case 2:
    auto_zap();
    break;
  default:
    printf("Неккоректные данные\n");
    break;
  }
}
