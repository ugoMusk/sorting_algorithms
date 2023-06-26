#ifndef SORT_H
#define SORT_H

#include <stdlib.h>
#include <stdio.h>
#include "print_array.c"
#include "0-bubble_sort.c"

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void print_list(const listint_t *list);
void print_array(const int *array, size_t size);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void insert_behind(listint_t *node, listint_t *key);
listint_t *pop_node(listint_t *key);
void swap(int *array, size_t x, size_t y);
size_t get_partition(int *array, size_t size, int start, int end);
void sort_it(int *array, size_t size, size_t start, size_t end);

/** Helper functions */
void swap_ints(int *a, int *b);


#endif
