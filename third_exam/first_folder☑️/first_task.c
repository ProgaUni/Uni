#include <stdlib.h>
#include <time.h>
#include "first_algorithm.h"

enum MENU {ManualInput=1, RandomInput=2, Quit=3};


int main(void)
{
    srand(time(NULL));
    int options = 1, loop_indicator = 1;
    
    Array array;
    printf("  Vsevolod Rybnik test 3 task 1 var 26\n");
    while (loop_indicator)
    {
		int rows = 0, cols = 0;
        int* result;
        puts("Specify matrix size:");
		while (rows <= 0){
		printf("\n  Rows *value must be >= 0: ");
        rows = get_int();
		}
		while (cols <= 0){
        printf("  Cols *value must be >= 0: ");
        cols = get_int();
		}
        puts("  1 - Manual input\n  2 - Random input\n  3 - Quit");
        options = get_int();
        switch (options)
        {
            default:
                puts("Dis value is not akceptabele\n");
            case Quit:
                puts("Bye, see you later");
                return EXIT_SUCCESS;
            case ManualInput:
                array = make_array(rows, cols, false);
                output(array);
                result = max_min_finder(array);
                printf("Min Element: %d\nMax Element: %d\n", result[0], result[1]);
                clean_space(&array);
                free(result);
                result = NULL;
                continue;
            case RandomInput:
                array = make_array(rows, cols, true);
                output(array);
                result = max_min_finder(array);
                printf("Min Element: %d\nMax Element: %d\n", result[0], result[1]);
                clean_space(&array);
                free(result);
                result = NULL;
                continue;
        }
    }
}
