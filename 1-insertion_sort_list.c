#include "sort.h"

/**
 * insertion_sort_list - Insertion sorted_tail algoithm with
 * doubly linked list
 * @list : pointer to address of doubly linked list to
 * be sorted_tailed
 *
 * Return: always void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t  *temp, *key, *sorted_tail;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	key = (*list)->next;  /* initialize key as second node of list */

	for (sorted_tail = *list; key != NULL; key = sorted_tail->next)
	{
		if (sorted_tail->n <= key->n)
		{
			sorted_tail = sorted_tail->next;
			key = sorted_tail->next;
			continue;
		}

		temp = sorted_tail; /* initialize iterator temp */

		while (1)  /* insertion loop with temp as iterator */
		{
			if (temp->prev == NULL)  /* insert at beginning */
			{
				(*list) = pop_node(key);
				key->next = temp;
				key->prev = NULL;
				temp->prev = key;
				print_list(*list);
				break;
			}
			else if (temp->n > key->n)
			{
				insert_behind(temp->prev, pop_node(key));
				temp = key->prev;
				print_list(*list);
			}
			else  /* key already placed in right position */
				break;
		}
	}
}


/**
 * insert_behind - Place a node "key" at the back of
 * another node "node" of doubly linked list
 * @node : pointer to first node in front of key
 * @key : pointer to second node placed after node
 *
 * Return: always void
 */
void insert_behind(listint_t *node, listint_t *key)
{
	listint_t *nxt;

	if (node == NULL || key == NULL)
		return;
	nxt = node->next;
	key->next = nxt;
	key->prev = node;
	node->next = key;
	nxt->prev = key;
}

/**
 * pop_node - Remove given node of a linked list
 * @key: pointer to node to remove
 *
 * Return: address of removed node
 */
listint_t *pop_node(listint_t *key)
{
	listint_t *prv = NULL, *nxt = NULL;

	prv = key->prev;
	nxt = key->next;
	if (prv != NULL)
		prv->next = nxt;
	if (nxt != NULL)
		nxt->prev = prv;

	return (key);
}
