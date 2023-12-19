#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int get_int(void)
{
  int input = 0;

  while (!scanf("%d", &input)){
    while (getchar() != '\n');
    puts("ќшибка ввода. ¬ведите целое число.");
  }

  while (getchar() != '\n');

  return input; 
}


void output(int array[], int ARRAY_LEN)
{
    printf("Array: [ %d", array[0]);
    for (int i = 1; i < ARRAY_LEN; i++)
    {
        printf(", ");
        printf("%d", array[i]);
    }
    printf("]\n");
}


int* bind_values(int array[], bool rand_indicator, int ARRAY_LEN)
{
    for (int i = 0; i < ARRAY_LEN; i++){
        if (rand_indicator){
            array[i] = -99 + rand()%(100+98);
        } else {
            printf("  - Specify %d element of Array: ", i+1);
            array[i] = get_int();
        }
    }
    return array;
}
