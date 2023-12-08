#include <math.h>
#include <locale.h>
#include <stdlib.h>
#include "first_interface.h"


#define upper_left_border 218
#define upper_right_border 191
#define lower_left_border 192
#define lower_right_border 217
#define underline 196
#define aside_border 179


struct TwoDimensionalArray {
    int rows;
    int cols;
    int **data;
};


typedef struct TwoDimensionalArray Array;


Array make_array(int rows, int cols, bool rand_man_indicator)
{
    Array array;
    array.rows = rows;
    array.cols = cols;
    array.data = (int **) malloc(array.rows * sizeof(int *));  // https://ufchgu.ru/blog/realloc-malloc-calloc-chem-zapolnjaet#:~:text=Функция%20malloc%20принимает%20один%20аргумент,количество%20элементов%20и%20их%20размер.
    for (int row = 0; row < array.rows; row++) {
        array.data[row] = (int *) malloc(array.cols * sizeof(int));
    }
    if (rand_man_indicator){
        for (int row = 0; row < array.rows; row++) {
            for (int col = 0; col < array.cols; col++) {
                array.data[row][col] = -99 + rand()%(100 + 98);
            }
        }
    }
    else
    {
        for (int row = 0; row < array.rows; row++) {
            for (int col = 0; col < array.cols; col++) {
                printf("  - Specify %d %d element of Matrix: ", row+1, col+1);
                array.data[row][col] = get_double();
            }
    }
    }
    return array;
}


void clean_space(Array *array)
{
    for (int row_index = 0; row_index < array->rows; row_index++) {
        free(array->data[row_index]);
        array->data[row_index] = NULL;
    }
    free(array->data);
    array->data = NULL;
}


void output(Array array)
{
    printf("  %c", upper_left_border);
    int underline_amount = 6 * array.cols + 2;
	for (int i = 1; i < underline_amount; i++)
		printf("%c", underline);
	printf("%c\n", upper_right_border);
    for (int row = 0; row < array.rows; row++) {
        for (int col = 0; col < array.cols; col++) {
            if (col == 0)
                printf("  %c", aside_border);
			if (array.data[row][col] >= 0)
				printf(" ");
			double digits = floor(log10(abs(array.data[row][col]))) + 1;
			printf("%*s", digits == 2? 2 : digits == 3? 1 : 3, " ");
            printf("%d ", array.data[row][col]);
        }
        printf(" %c\n", aside_border);
    }
	printf("  %c", lower_left_border);
	for (int i = 1; i < underline_amount; i++)
		printf("%c", underline);
	printf("%c\n", lower_right_border);
}
