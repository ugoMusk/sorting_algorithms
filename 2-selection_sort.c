#include "sort.h"

/**
 * selection_sort - Sort an array using selection
 * sort algorithm
 * @array: array to sort
 * @size: size of array
 *
 * Return: always void
 */
void selection_sort(int *array, size_t size)
{
	size_t index = 0, min_idx, i, found_min;

	if (array == NULL || size < 2)
		return;
	for (; index < size - 1; index++)
	{
		min_idx = index;
		found_min = index + 1;
		for (i = index + 1; i < size; i++)
		{
			if (array[i] < array[found_min])
				found_min = i;
		}
		if (array[min_idx] > array[found_min])
		{
			swap(array, min_idx, found_min);
			print_array(array, size);
		}
	}
}
