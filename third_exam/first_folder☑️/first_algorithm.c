#include "first_struct.h"


int* max_min_finder(Array array)
{
    int* result = (int*)calloc(2, sizeof(int));  // 0 элемент - min, 1 - max
    result[0] = array.data[array.rows-1][array.cols-1];
    result[1] = array.data[array.rows-1][array.cols-1];
    for (int rows = 1; rows < array.rows; rows++)
    {
        for (int cols = array.cols - (rows + 1); cols < array.cols; cols++)
        {
            result[0] = (array.data[rows][cols] < result[0])? array.data[rows][cols] : result[0];
            result[1] = (array.data[rows][cols] > result[1])? array.data[rows][cols] : result[1];
        }
    }
    return result;
}

