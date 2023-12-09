#include <locale.h>
#include <time.h>
#include "second_interface.h"
#include "second_algorithm.h"

#define EL_AMOUNT 8

enum MENU {Man=1, Rand=2, Quit=3};


int main(void)
{
    setlocale (LC_CTYPE, "RU");
    srand(time(NULL));
    int loop_indicator = 1, options = 1;
    printf("  Vsevolod Rybnik test 3 task 2 var 26\n");
    while (loop_indicator)
    {
        char sequence[EL_AMOUNT];
        char* bits;
        puts("  1 - Manual input\n  2 - Random input\n  3 - Quit");
        options = get_int();
        switch (options)
        {
            case Man:
                puts("Specify your symbols sequence: ");
                get_sequence(sequence, EL_AMOUNT);
                bits = algorithm(sequence, EL_AMOUNT);
                printf("...And result is -> %s\n", bits);
                printf("In ASCII - %s\n", back_to_char(bits, EL_AMOUNT));
                free(bits);
                continue;
            case Rand:
                printf(
                    "Your random symbol sequence is %s\n",
                    get_random_sequence(sequence, EL_AMOUNT)
                );
                bits = algorithm(sequence, EL_AMOUNT);
                printf("...And result is -> %s\n", bits);
                printf("In ASCII - %s\n", back_to_char(bits, EL_AMOUNT));
                free(bits);
                continue;
            case Quit:
                puts("  Bye, see you later!");
                return EXIT_SUCCESS;
            default:
                puts("  Dis value is not akceptabele\n");
        }
    }
}


