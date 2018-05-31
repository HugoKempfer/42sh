/*
** EPITECH PROJECT, 2018
** add_alias.c
** File description:
** add_alias.c
*/

#include "42sh.h"
#include "alias.h"
#include "metadata.h"
#include "list.h"
#include "tools.h"

char *get_alias_value(llist_t *alias, char *name)
{
	lnode_t *node = alias->head;

	while (node) {
		if (!strcmp(name, ((alias_t *)(node->data))->name)) {
			return (((alias_t *)(node->data))->value);
		}
		node = node->next;
	}
	return (NULL);
}

llist_t *process_alias(shell_info_t *infos,  char *name)
{
	llist_t *alias_list = list_init(NULL);
	char *alias_value = get_alias_value(infos->alias, name);

	if (!list_push_tail(alias_value, alias_list)) {
		return (NULL);
	}
	return (alias_list);
}
