#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of ints in ascending order
 * @list: list
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *node = NULL, *aux = NULL;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	node = *list;
	node = node->next;
	while (node)
	{
		while (node->prev && node->n < (node->prev)->n)
		{
			aux = node;
			if (node->next)
				(node->next)->prev = aux->prev;
			(node->prev)->next = aux->next;
			node = node->prev;
			aux->prev = node->prev;
			aux->next = node;
			if (node->prev)
				(node->prev)->next = aux;
			node->prev = aux;
			if (aux->prev == NULL)
				*list = aux;
			print_list(*list);
			node = node->prev;
		}
		node = node->next;
	}
}
