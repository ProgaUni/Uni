#include <time.h>
#include "third_interface.h"
#include "third_algorithm.h"




enum MENU {Man=1, Rand=2, Quit=3};


int main(void)
{
    srand(time(NULL));
    int ARRAY_LEN = 0;
    int loop_indicator = 1, options = 1;
    int* array = (int*)malloc(sizeof(int));
    printf("  Vsevolod Rybnik test 3 task 3 var 26\n");
    while (loop_indicator)
    {
        puts("Specfiy array length: ");
        ARRAY_LEN = get_int();
        puts("  1 - Manual input\n  2 - Random input\n  3 - Quit");
        options = get_int();
        switch (options)
        {
            case Man:
                bind_values(array, false, ARRAY_LEN);
                printf("Result: %d \n", fold(array, ARRAY_LEN, algorithm));
                output(array, ARRAY_LEN);
                continue;
            case Rand:
                bind_values(array, true, ARRAY_LEN);
                output(array, ARRAY_LEN);
                printf("Result: %d \n", fold(array, ARRAY_LEN, algorithm));
                continue;
            case Quit:
                puts("  Bye, see you later!");
                return EXIT_SUCCESS;
            default:
                puts("  Dis value is not akceptabele\n");
        }
    }
}
