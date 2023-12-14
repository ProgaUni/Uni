#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int get_int(void)
{
    char temprem, tempclear;
    int input  = 0;
    while(true)
    {
        temprem=0;
        tempclear=0;
        if((!scanf("%d%c",&input ,&temprem))|| temprem != '\n' || input <= 0)
        {
            printf("  - Error: Invalid value for int variables.\nOne more time: ");
        	while(tempclear != '\n')
            	scanf("%c",&tempclear);
        }
    else
        return input;
    }
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
