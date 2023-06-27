#include "sort.h"

/**
 * quick_sort - Sort a given array using quick sort algorithm
 * @array: pointer to array of integers
 * @size: size of array
 *
 * Return: always void
 */
void quick_sort(int *array, size_t size)
{
	size_t start, end;

	if (size < 2 || array == NULL)
		return;
	end = size - 1;
	start = 0;
	do_quick_sort(array, size, start, end);
}

/**
 * do_quick_sort - Recursively Sort an array with quicksort algorithm
 * @array: pointer to array to sort
 * @size: size of array
 * @start: start index of array
 * @end: end index of array
 *
 * Return: always void
 */
void do_quick_sort(int *array, size_t size, size_t start, size_t end)
{
	size_t partition;

	if (start >= end)
		return;
	partition = get_partition(array, size, start, end);
	if (partition != 0)
		do_quick_sort(array, size, start, partition - 1);
	do_quick_sort(array, size, partition + 1, end);
}

/**
 * get_partition - Get the next partition point of array
 * @array: array of integers
 * @size: size of array
 * @start: start index of array
 * @end: end index of array
 *
 * Return: position to partion the array
 */
size_t get_partition(int *array, size_t size, int start, int end)
{
	size_t piv_idx = end, lo = start, hi = end;

	while (lo < hi)
	{
		while (array[hi] >= array[piv_idx] && hi > 0)
			hi--;
		while (array[lo] < array[piv_idx] && lo < size)
			lo++;
		if (hi > lo && array[hi] != array[lo])
		{
			quick_swap(array, hi, lo);
			print_array(array, size);
		}
	}
	if (lo >= hi && lo != piv_idx && array[lo] != array[piv_idx])
	{
		quick_swap(array, lo, piv_idx);
		print_array(array, size);
	}
	return (lo);
}

/**
 * quick_swap - Swaps two items in a given array
 * @array: array of integer
 * @x: index of first item
 * @y: index of second item
 *
 * Return: always void
 */
void quick_swap(int *array, size_t x, size_t y)
{
	int temp;

	temp = array[x];
	array[x] = array[y];
	array[y] = temp;
}
