#include "sort.h"

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
 * lomuto_partition - partitions the array according to lomuto theory
 * @array: the integers to be sorted
 * @size: the propotions of the array
 * @left: The one on the left(begin)
 * @right: The one on the right(end)
 *
 * Return: The final partition index.
 */
int lomuto_partition(int *array, size_t size, int left, int right)
{
	int *pivot = array + right;
	int above, below;

	for (above = below = left; below < right; below++)
	{
		if (array[below] < *pivot)
		{
			if (above < below)
			{
				swap_int(array + below, array + above);
				print_array(array, size);
			}
			above++;
		}
	}

	if (array[above] > *pivot)
	{
		swap_int(array + above, pivot);
		print_array(array, size);
	}

	return (above);
}

/**
 * lomuto_sort - functions to carry out the execution of quick sort algorithm
 * @array: the integers to be sorted using the quick sort algorithm
 * @size: The propotions of the array
 * @left: The one on the left(begin)
 * @right: The one on the right(end)
 *
 */
void lomuto_sort(int *array, size_t size, int left, int right)
{
	int x;

	if (right - left > 0)
	{
		x = lomuto_partition(array, size, left, right);
		lomuto_sort(array, size, left, x - 1);
		lomuto_sort(array, size, part + 1, right);
	}
}

/**
 * quick_sort -  functions to sort array of integers in ascending order
 * using the quick sort algorithm
 * @array: The integers to be sorted using the quick sort algorithm
 * @size:  the propotions of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	lomuto_sort(array, size, 0, size - 1);
}
