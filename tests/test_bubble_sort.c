#include "sort.h"

/** test for the bubble_sort algorithm
   main - entry point
   @array: array to sort
   @size: size of arrray

*/


int main(void){

  int array[] = {2,4,8,1,9,5,0,3};
  size_t size = sizeof(array) / sizeof(array[0]);

  bubble_sort(array, size);
}
