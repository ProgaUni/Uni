#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define TABLE_SIZE 4


typedef struct {
    char* key;
    double value;
} Entry;

typedef struct {
    Entry* entries;
    int size;
} HashTable;


int hash(char* key) {
    int hashValue = 0;
    for (int i = 0; i < (int)strlen(key); i++) {
        hashValue ^= (int)(unsigned char) key[i];
        hashValue += key[i];
    }
    return hashValue;
}


HashTable* createHashTable(void) {
    HashTable* hashTable = (HashTable*) malloc(sizeof(HashTable));
    hashTable->entries = (Entry*) malloc(TABLE_SIZE * sizeof(Entry));
    hashTable->size = TABLE_SIZE;
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable->entries[i].key = NULL;
    }
    return hashTable;
}

void insert(HashTable* hashTable, char* key, int value) {
    int index = hash(key);
    while (hashTable->entries[index].key!= NULL) {
        if (strcmp(hashTable->entries[index].key, key) == 0) {
            hashTable->entries[index].value = value;
            return;
        }
        index = (index + 1) % hashTable->size;
    }
    hashTable->entries[index].key = strdup(key);
    hashTable->entries[index].value = value;
}

int get(HashTable* hashTable, char* key) {
    int index = hash(key);
    while (hashTable->entries[index].key!= NULL) {
        if (strcmp(hashTable->entries[index].key, key) == 0) {
            return hashTable->entries[index].value;
        }
        index = (index + 1) % hashTable->size;
    }
    return 0;
}


void destroyHashTable(HashTable* hashTable) {
    for (int i = 0; i < hashTable->size; i++) {
        if (hashTable->entries[i].key!= NULL) {
            free(hashTable->entries[i].key);
			hashTable->entries[i].key = NULL;
        }
    }
    free(hashTable->entries);
	hashTable->entries = NULL;
    free(hashTable);
	hashTable = NULL;
}
