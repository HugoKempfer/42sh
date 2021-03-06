/*
** EPITECH PROJECT, 2018
** Doubly linked list
** File description:
** Useful functions to use with the llist
*/

#include "list.h"
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

char **list_to_arr(llist_t *list)
{
	lnode_t *node = list->head;
	char **array = malloc(sizeof(*array) * (list->nb_nodes + 1));
	char **ptr = array;

	if (!array) {
		free(array);
		return (NULL);
	}
	while (node) {
		*ptr = node->data;
		node = node->next;
		++ptr;
	}
	*ptr = NULL;
	return (array);
}

llist_t *arr_to_list(char **buffer)
{
	llist_t *list = list_init(NULL);

	while (*buffer) {
		list_push_tail(*buffer, list);
		++buffer;
	}
	return (list);
}

llist_t *arr_dup_to_list(char **buffer)
{
	llist_t *list = list_init(NULL);

	while (*buffer) {
		list_push_tail(strdup(*buffer), list);
		++buffer;
	}
	return (list);
}

lnode_t *list_index(int nb_nodes, lnode_t *beacon_node)
{
	if (nb_nodes != 0 && beacon_node->next != NULL) {
		return (list_index(nb_nodes - 1, beacon_node->next));
	}
	return (beacon_node);
}
