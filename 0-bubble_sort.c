#include "sort.h"
#include <stdbool.h>

/**
 * swap_int - functions to swap two ints.
 * @a: integer one for swapping
 * @b: integers two for swapping
 */
void swap_int(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * bubble_sort -  sorts an array of integers using bubble sort algorithm
 * @array: the integers to be sorted using the bubbl sort algorithm
 * @size: the propotions of the array
 */

void bubble_sort(int *array, size_t size)
{
	size_t x, y = size;
	bool swap;

	if (!array || size < 2)
		return;

	do {
		swap = false;
		for (x = 0; x < y - 1; x++)
		{
			if (array[x] > array[x + 1])
			{
				swap_int(&array[x], &array[x + 1]);
				print_array(array, size);
				swap = true;
			}
		}
		y--;
	} while (swap);
}

