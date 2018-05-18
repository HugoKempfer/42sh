/*
** EPITECH PROJECT, 2018
** MiniShell
** File description:
** Function to pop nodes and free the list
*/

#include "tools.h"
#include "list.h"

static void list_destroy_node(lnode_t *node, llist_t *list)
{
	if (!(list->destroyer)) {
		return;
	}
	(list->destroyer)(node->data);
	free(node);
}

void	list_pop(lnode_t *node, llist_t *list)
{
	if (node->next == NULL && node->prev == NULL) {
		list->head = NULL;
		list->tail = NULL;
	} else if (node->next == NULL || node->prev == NULL) {
		if (node->next == NULL && node->prev != NULL) {
			node->prev->next = node->next;
			list->tail = node->prev;
		}
		else if (node->prev == NULL && node->next != NULL){
			node->next->prev = node->prev;
			list->head = node->next;
		}
	} else {
		node->prev->next = node->next;
		node->next->prev = node->prev;
	}
	list->nb_nodes--;
	if (list->nb_nodes != 0)
		list_destroy_node(node, list);
}

void list_destroy(llist_t *list)
{
	lnode_t *tmp = list->head;
	lnode_t *current = NULL;

	if (!(tmp)) {
		return;
	}
	while (tmp) {
		current = tmp;
		tmp = tmp->next;
		list_pop(current, list);
	}
	free(list);
}
