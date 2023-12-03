#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* algorithm(char* sequence, int seq_len) {
    char* bits = (char*)malloc(64); // массив для хранения битов

    for (int i = 0; i < seq_len; i++) {
        char c = sequence[i];
        sprintf(bits + i * 8, "%08d", c);
    }

    for (int i = 0; i < seq_len; i++) {
        int firstBit = bits[i * 8] - '0';
        int lastBit = bits[i * 8 + 7] - '0';
        if (firstBit == lastBit) {
            bits[i * 8] = '0';
            bits[i * 8 + 7] = '1';
        } else {
            bits[i * 8] = '1';
            bits[i * 8 + 7] = '0';
        }
    }

    return bits;
}