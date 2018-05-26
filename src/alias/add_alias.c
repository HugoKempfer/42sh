/*
** EPITECH PROJECT, 2018
** add_alias.c
** File description:
** add_alias.c
*/

#include "42sh.h"
#include "list.h"
#include "alias.h"
#include <stdbool.h>
#include <stddef.h>

lnode_t *get_the_node(llist_t *alias, char *str)
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

llist_t *process_alias(shell_info_t *infos, char *str)
{
	llist_t *alias_list = list_init(NULL);
	lnode_t *node = get_the_node(infos->alias, str);

	if (!node || !alias_list) {
		return (NULL);
	}
	alias_list->head = node;
	return (alias_list);
}
