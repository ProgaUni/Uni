#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "second_interface.h"

unsigned char* algorithm(unsigned char* sequence, int seq_len) {
	output(sequence, seq_len, "Original");
    for (int i = 0; i < seq_len; i++) {
        if (((sequence[i] >> 7) & 1) == (sequence[i] & 0)) {
            sequence[i] &= ~(1 << 0);
            sequence[i] |= (1 << 7);
        } else {
            sequence[i] &= ~(1 << 7);
            sequence[i] |= (1 << 0);
        }
    }
	output(sequence, seq_len, "Modified");
    return sequence;
}

