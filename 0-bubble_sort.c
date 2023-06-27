#include "sort.h"

/**
 * swap_items - Swaps two items in a given array
 * @array: array of integer
 * @x: index of first item
 * @y: index of second item
 *
 * Return: always void
 */
void swap_items(int *array, size_t x, size_t y)
{
        int temp;

        temp = array[x];
        array[x] = array[y];
        array[y] = temp;
}

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
				swap_items(array, j, j + 1);
				print_array(array, size);
				swapped++;
			}
		}
		if (i == 1 && swapped == 0)
			return;
	}
}
