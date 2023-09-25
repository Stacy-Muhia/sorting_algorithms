#include "sort.h"

/**
 * node_swp - functions to swap two nodes in a listint_t linked list.
 * @head: A pointer to the head of the doubly-linked list.
 * @node1: node one to swap.
 * @node2: node two to swap.
 */
void node_swp(listint_t **head, listint_t **node1, listint_t *node2)
{
	(*node1)->next = node2->next;
	if (node2->next != NULL)
		node2->next->prev = *node1;
	node2->prev = (*node1)->prev;
	node2->next = *node1;
	if ((*node1)->prev != NULL)
		(*node1)->prev->next = node2;
	else
		*head = node2;
	(*node1)->prev = node2;
	*node1 = node2->prev;
}

/**
 * insertion_sort_list -  functions to sort double linked-list of int in asc.
 * @list:  the list to be sorted in ascending ordee
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *x, *insert, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (x = (*list)->next; x != NULL; x = temp)
	{
		temp = x->next;
		insert = x->prev;
		while (insert != NULL && x->n < insert->n)
		{
			node_swp(list, &insert, x);
			print_list((const listint_t *)*list);
		}
	}
}
