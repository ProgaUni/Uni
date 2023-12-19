#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


int get_int(void);
unsigned char* get_random_sequence(unsigned char* sequence, int length);
unsigned char* get_sequence(unsigned char* sequence, int length);
void output(unsigned char* sequence, int seq_len, char* key_word);
