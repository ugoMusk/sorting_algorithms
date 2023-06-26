#include "sort.h"


/**
 * swap_ints - Swap two integers in an array.
 * @first_num: The first integer to swap.
 * @second_num: The second integer to swap.
 */
void swap_ints(int *first_num, int *second_num){
    
  int tmp;

  tmp = *first_num;
  *first_num = *second_num;
  *second_num = tmp;
}

/**
 * bubble_sort - sort in bubbles
 * @array: array to sort
 * @size: size
 *
 */
void bubble_sort(int *array, size_t size){
    
  size_t index, newsize = size;
  int swap;

  if (array == NULL || size < 2)
    return;

  while (newsize)
    {
      swap = 0;
      for (index = 0; index < (size - 1); index++)
	{
	  if (array[index] > array[index + 1])
	    {
	      swap_ints(&array[index], &array[index + 1]);
	      print_array(array, size);
	      swap += 1;
	    }
	}

      printf("swaps: %d\n", swap);
      newsize--;
      if (swap == 0)
	break;
    }
}

