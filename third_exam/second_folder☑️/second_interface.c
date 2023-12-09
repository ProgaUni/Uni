#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


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
	char temprem, tempclear;
    while(true)
    {
        temprem=0;
        tempclear=0;
		sequence[0]='\0';
        if((!scanf("%s",sequence))|| (int)strlen(sequence) != length)
        {
            printf("  - Error: Invalid value for 8 length string sequence.\nOne more time: ");
        	while(tempclear != '\n')
            	scanf("%c",&tempclear);
        }
    	else
        	return sequence;
    }
}


char* get_random_sequence(char* sequence, int length)
{
    for (int i = 0; i < length; i++) {
        sequence[i] = rand() % 26 + 'A';
    }
    sequence[8] = '\0';
    return sequence;
}


char* back_to_char(char* bits, int seq_len)
{
    char* result = (char*) malloc(seq_len + 1);
    for (int i = 0; i < seq_len; i++) {
        char c = 0;
        for (int j = 0; j < 8; j++) {
            c = (c << 1) | (bits[i * 8 + j] - '0');
        }
        result[i] = c;
    }
    result[seq_len] = '\0';
    return result;
}
