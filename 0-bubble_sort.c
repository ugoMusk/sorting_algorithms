#include "sort.h"

/**
 * bubble_sort - sort in bubbles
 * @array: array to sort
 * @size: size
 *
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int swapped = 0;

	if (array == NULL || size < 2)
		return;
	for (i = 1; i < size; i++)
	{
		for (j = 0; j < size - i; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap(array, j, j + 1);
				print_array(array, size);
				swapped++;
			}
		}
		if (i == 1 && swapped == 0)
			return;
	}
}
