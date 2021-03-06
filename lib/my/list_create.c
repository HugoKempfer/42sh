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

int	list_push_head(void *data, llist_t *list)
{
	lnode_t *node = list_create_node(data);

	if (!(node)) {
		return (false);
	}
	if (!(list->head)) {
		list->head = node;
		list->tail = node;
	} else {
		list->head->prev = node;
		node->next = list->head;
		list->head = node;
	}
	++(list->nb_nodes);
	return (true);
}

int	list_push_tail(void *data, llist_t *list)
{
	lnode_t *node = list_create_node(data);

	if (!(node)) {
		return (false);
	}
	if (!(list->tail)) {
		list->head = node;
		list->tail = node;
	} else {
		list->tail->next = node;
		node->prev = list->tail;
		list->tail = node;
	}
	++(list->nb_nodes);
	return (true);
}
