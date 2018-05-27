/*
** EPITECH PROJECT, 2018
** var_helpers.c
** File description:
** helpers for managing local/global shell variables
*/

#include "functions.h"
#include "list.h"
#include "var.h"
#include <string.h>

bool set_var(llist_t *var_list, const char *name, const char *value)
{
	lnode_t *node = var_list->head;
	var_t *var = NULL;

	while (node) {
		if (!strcmp(((var_t *)node->data)->name, name)) {
			free(((char *)((var_t *)node->data)->value));
			((var_t *)node->data)->value = value;
			return (true);
		}
		node = node->next;
	}
	var = init_struct_var(name, value);
	if (!list_push_tail(var, var_list)) {
		return (false);
	}
	return (true);
}

bool remove_var(llist_t *var_list, const char *name)
{
	lnode_t *node = var_list->head;
	var_t *var = NULL;

	while (node) {
		if (!strcmp(((var_t *)node->data)->name, name)) {
			list_pop(node, var_list);
			return (true);
		}
		node = node->next;
	}
	return (false);
}