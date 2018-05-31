/*
** EPITECH PROJECT, 2018
** var_management
** File description:
** manage the var funcs
*/

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "list.h"
#include "var.h"
#include "my.h"
#include "42sh.h"

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

llist_t *process_value(llist_t *var_list, char *name)
{
	llist_t *empty_list = list_init(NULL);
	char *value_var = find_value_var(var_list, name);

	if (!empty_list || !value_var) {
		return (NULL);
	}
	if (!list_push_tail(value_var, empty_list)) {
		return (NULL);
	}
	return (empty_list);
}

void print_the_var(lnode_t *node, char **command)
{
	while (node) {
		if (!strcmp(&command[0][1], ((var_t *)node->data)->name)) {
			my_putstr(((var_t *)node->data)->name);
			if (((var_t *)node->data)->value) {
				my_putstr(" == ");
				puts(((var_t *)node->data)->value);
			}
			return;
		}
		node = node->next;
	}
	my_putstr(&command[0][1]);
}

int var_manager(shell_info_t *info, char **command)
{
	set_var(info, command);
	remove_var(info, command);
	return (0);
}
