#include <stdlib.h>
#include <time.h>
#include "first_algorithm.h"

#define ROWS 6
#define COLS 6

enum MENU {ManualInput=1, RandomInput=2, Quit=3};


int main(void)
{
    srand(time(NULL));
    int options = 1, loop_indicator = 1;
    Array array;
    printf("  Vsevolod Rybnik test 3 task 1 var 26\n");
    while (loop_indicator)
    {
        int* result;
        puts("  1 - Manual input\n  2 - Random input\n  3 - Quit");
        options = GetDouble();
        switch (options)
        {
            default:
                puts("Dis value is not akceptabele\n");
            case Quit:
                puts("Bye, see you later");
                return EXIT_SUCCESS;
            case ManualInput:
                array = make_array(ROWS, COLS, false);
                output(array);
                result = max_min_finder(array);
                printf("Min Element: %d\nMax Element: %d\n", result[0], result[1]);
                clean_space(&array);
                continue;
            case RandomInput:
                array = make_array(ROWS, COLS, true);
                output(array);
                result = max_min_finder(array);
                printf("Min Element: %d\nMax Element: %d\n", result[0], result[1]);
                clean_space(&array);
                continue;
        }
    }
}
