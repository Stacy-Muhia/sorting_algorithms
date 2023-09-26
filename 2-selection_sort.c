#include "sort.h"

/**
 * selection_sort - sorts an  array in asd order using selection sort algorithm
 * @array: the integers to be sorted using the selection sort algorithm
 * @size: the propotions of the array
 */
void selection_sort(int *array, size_t size)
{
	size_t tmp, idx, min;
	int temp;

	if (array == NULL || size < 2)
		return;

	for (tmp = 0; tmp < size - 1; tmp++)
	{
		min = tmp;

		for (idx = tmp + 1; idx < size; idx++)
		{
			if (array[idx] < array[min])
				min = idx;
		}

		if (min != tmp)
		{
			temp = array[tmp];
			array[tmp] = array[min];
			array[min] = temp;
			print_array(array, size);
		}
	}
}
