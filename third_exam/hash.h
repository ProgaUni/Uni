typedef struct {
    char* key;
    double value;
} Entry;

typedef struct {
    Entry* entries;
    int size;
} HashTable;

void destroyHashTable(HashTable* hashTable);

int get(HashTable* hashTable, char* key);

void insert(HashTable* hashTable, char* key, int value);

HashTable* createHashTable(void);
