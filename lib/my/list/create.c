/*
** EPITECH PROJECT, 2017
** my_list
** File description:
** Linked list functions, create, delete, insert nodes.
*/

#include "list.h"
#include "tools.h"

llist_t *list_init(destroy_func_t *destroyer)
{
	llist_t *list = malloc(sizeof(*list));

	if (!(list)) {
		return (NULL);
	}
	list->nb_nodes = 0;
	list->head = NULL;
	list->tail = NULL;
	list->destroyer = destroyer;
	return (list);
}

lnode_t *list_create_node(void *data)
{
	lnode_t *node = malloc(sizeof(*node));

	if (!(node)) {
		return (NULL);
	}
	node->next = NULL;
	node->prev = NULL;
	node->data = data;
	return (node);
}

void	list_push_head(void *data, llist_t *list)
{
	lnode_t *node = list_create_node(data);

	if (!(node)) {
		return;
	}
	if (!(list->head)) {
		list->head = node;
		list->tail = node;
	}
	else {
		list->head->prev = node;
		node->next = list->head;
		list->head = node;
	}
	++(list->nb_nodes);
}

void	list_push_tail(void *data, llist_t *list)
{
	lnode_t *node = list_create_node(data);

	if (!(node)) {
		return;
	}
	if (!(list->tail)) {
		list->head = node;
		list->tail = node;
	}
	else {
		list->tail->next = node;
		node->prev = list->tail;
		list->tail = node;
	}
	++(list->nb_nodes);
}

lnode_t	*list_index(int nb_nodes, lnode_t *beacon_node)
{
	if (nb_nodes != 0 && beacon_node->next != NULL) {
		return (list_index(nb_nodes - 1, beacon_node->next));
	}
	return (beacon_node);
}
