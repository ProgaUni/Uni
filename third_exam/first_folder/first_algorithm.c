#include "first_struct.h"
#include "../hash.h"


HashTable* algorithm(Array array, HashTable* min_max_table)
{
    insert(min_max_table, "min", array.data[0][array.cols-1]);
    insert(min_max_table, "max", array.data[0][array.cols-1]);
    for (int rows = 1; rows < array.rows; rows++)
    {
        for (int cols = array.cols - (rows + 1); cols < array.cols; cols++)
        {
            insert(min_max_table, "min", (array.data[rows][cols] < get(min_max_table, "min"))? array.data[rows][cols] : get(min_max_table, "min"));
            insert(min_max_table, "max", (array.data[rows][cols] > get(min_max_table, "max"))? array.data[rows][cols] : get(min_max_table, "max"));
        }
    }
    return min_max_table;
}