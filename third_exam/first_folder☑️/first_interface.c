#include <stdio.h>
#include <stdbool.h>


double GetDouble(void)
{
    char temprem, tempclear; // временный остаток
    double input  = 0;
    while(true)
    {
        temprem = 0;
        tempclear = 0;
        if((!scanf("%lf%c",&input ,&temprem))|| temprem != '\n')
        {
            printf("  - Error: Invalid value for double variables.\n  - One more time: ");
        	while(tempclear != '\n')
            	scanf("%c",&tempclear);
        }
    else
        return input;
    }
}
