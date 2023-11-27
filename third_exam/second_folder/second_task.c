#include <stdio.h>
#include <stdlib.h>

enum MENU {Man=1, Rand=2, Quit=3}


int main(void)
{
    int loop_indicator = 1, options = 1;
    printf("  Vsevolod Rybnik test 3 task 2 var 26\n");
    while (loop_indicator)
    {
        puts("  1 - Manual input\n  2 - Random input\n  3 - Quit");
        options = GetDouble();
        switch (options)
        {
            case Quit:
                puts("Bye, see you later!");
                return EXIT_SUCCESS;
            default:
                puts("Dis value is not akceptabele\n");
        }
    }
}
