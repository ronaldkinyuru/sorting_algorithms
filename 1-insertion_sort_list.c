#include "sort.h"

/**
 * swap_nodes - Swaps two nodes in a doubly linked list
 * @list: pointer to the head of doubly linked list
 * @node1: The first node
 * @node2: The second node
 */
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
	if (node1->prev)
		node1->prev->next = node2;
	if (node2->next)
		node2->next->prev = node1;
	node1->next = node2->next;
	node2->prev = node1->prev;
	node1->prev = node2;
	node2->next = node1;
	if (!node2->prev)
		*list = node2;
}

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending
 * order using the Insertion sort algorithm
 * @list: Double pointer to the head of the doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *tmp;

	if (!list || !(*list))
		return;

	current = (*list)->next;
	while (current)
	{
		tmp = current;
		current = current->next;
		while (tmp->prev && tmp->n < tmp->prev->n)
		{
			swap_nodes(list, tmp->prev, tmp);
			print_list(*list);
		}
	}
}
