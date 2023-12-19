#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


#define EL_AMOUNT 8


int get_int(void)
{
    char temprem, tempclear;
    int input  = 0;
    while(true)
    {
        temprem=0;
        tempclear=0;
        if((!scanf("%d%c",&input ,&temprem))|| temprem != '\n')
        {
            printf("  - Error: Invalid value for int variables.\nOne more time: ");
        	while(tempclear != '\n')
            	scanf("%c",&tempclear);
        }
    	else
        	return input;
    }
}

char* get_sequence(char* sequence, int length){
	char tempclear;
    while(true)
    {
        tempclear=0;
        if((!scanf("%8s", sequence))|| (int)strlen(sequence) != length)
        {
            printf("  - Error: Invalid value for 8 length string sequence.\nOne more time: ");
        	while(tempclear != '\n')
            	scanf("%c",&tempclear);
        }
    	else
			while (getchar() != '\n');
			printf("%s\n", sequence);
        	return sequence;
    }
}


char* get_random_sequence(char* sequence, int length)
{
    for (int i = 0; i < length; i++) {
        sequence[i] = rand() % 100 + 'A';
    }
    sequence[8] = '\0';
    return sequence;
}


void output(char* sequence, int seq_len, char* key_word){
	for (int element = 0; element < seq_len; element++){
		printf("%s bitwise representation of '%c': ", key_word, sequence[element]);
		for (int i = 7; i >= 0; i--) {
        	printf("%d", ((sequence[element] >> i) & 1));
    	}
		printf(", Oct: %o\n", sequence[element]);
	}
	puts("");
}
