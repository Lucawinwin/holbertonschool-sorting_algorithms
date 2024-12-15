#include "sort.h"

/**
* insertion_sort_list - function that sorts a doubly linked list of
* integers with insertion sort algorithm.
* @list: doubly linked list
*
*/

void insertion_sort_list(listint_t **list)
{
	listint_t *i_node, *a_node;

	if (list == NULL || *list == NULL)
		return;

	a_node = (*list)->next;

	while (a_node)
	{
		i_node = (*a_node).next;
		while ((*a_node).prev && (*a_node).n < (*a_node).prev->n)
		{
			(*a_node).prev->next = (*a_node).next;
			if ((*a_node).next)
				(*a_node).next->prev = (*a_node).prev;
			(*a_node).next = (*a_node).prev;
			if ((*a_node).next)
			{
				(*a_node).prev = (*a_node).next->prev;
				(*a_node).next->prev = a_node;
			}
			if ((*a_node).prev)
				(*a_node).prev->next = a_node;
			else
				(*list) = a_node;
			print_list(*list);
		}
		a_node = i_node;
	}
}
