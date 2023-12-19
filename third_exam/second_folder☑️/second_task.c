#include <locale.h>
#include <time.h>
#include "second_interface.h"
#include "second_algorithm.h"

#define EL_AMOUNT 8

enum MENU {Man=1, Rand=2, Quit=3};


int main(void)
{
    
    srand(time(NULL));
	setlocale(LC_ALL, "Russian");
    int loop_indicator = 1, options = 1;
    printf("  Vsevolod Rybnik test 3 task 2 var 26\n");
    while (loop_indicator)
    {
        
        puts("  1 - Manual input\n  2 - Random input\n  3 - Quit");
        options = get_int();
		unsigned char sequence[EL_AMOUNT];
        switch (options)
        {
            case Man:
                puts("Specify your symbols sequence, in case overflow it will take first 8: ");
                get_sequence(sequence, EL_AMOUNT);
                algorithm(sequence, EL_AMOUNT);
                printf("\n...And result is -> %s\n", sequence);
                continue;
            case Rand:
                printf(
                    "Your random symbol sequence is %s\n",
                    get_random_sequence(sequence, EL_AMOUNT)
                );
				
                algorithm(sequence, EL_AMOUNT);
                printf("\n...And result is -> %s\n", sequence);
				
                continue;
            case Quit:
                puts("  Bye, see you later!");
                return EXIT_SUCCESS;
            default:
                puts("  Dis value is not akceptabele\n");
        }
    }
}


