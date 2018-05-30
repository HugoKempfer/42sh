/*
** EPITECH PROJECT, 2018
** get_alias_node.c
** File description:
** get_alias_node.c
*/

#include "42sh.h"
#include "list.h"
#include "alias.h"

lnode_t *get_alias_node(llist_t *alias, char *str)
{
	lnode_t *node = alias->head;

	while (node) {
		if (!strcmp(str, ((alias_t *)(node->data))->name)) {
			return (node);
		}
		node = node->next;
	}
	return (NULL);
}
