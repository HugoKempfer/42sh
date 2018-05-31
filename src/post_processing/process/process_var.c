/*
** EPITECH PROJECT, 2018
** var_management
** File description:
** manage the var funcs
*/

#include "42sh.h"
#include "metadata.h"
#include "list.h"
#include "var.h"
#include "tools.h"
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char *find_value_var(llist_t *var_list, char *name)
{
	lnode_t *node = var_list->head;

	while (node) {
		if (!strcmp(name, ((var_t *)(node->data))->name)) {
			return (((char *)((var_t *)(node->data))->value));
		}
		node = node->next;
	}
	return (NULL);
}

llist_t *process_var(shell_info_t *infos, unused tree_metadata_t *meta,
			char *name)
{
	llist_t *empty_list = list_init(NULL);
	char *value_var = find_value_var(infos->local_vars, name + 1);

	if (!empty_list || !value_var) {
		return (NULL);
	}
	if (!list_push_tail(value_var, empty_list)) {
		return (NULL);
	}
	return (empty_list);
}
