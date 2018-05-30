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
#include "42sh.h"

size_t grid_len(char **grid)
{
	size_t word_idx = 0;

	if (!grid) {
		return (0);
	}
	while (grid[word_idx++]);
	return (--word_idx);
}

bool is_setting_the_var(char **cmd, char **name_or_value, shell_info_t *info)
{
	if (!strcmp(cmd[0], "set") && grid_len(cmd) >= 2) {
		if (grid_len(cmd) == 4 && !strcmp(cmd[2], "=")) {
			name_or_value[1] = cmd[3];
			return (true);
		}
		else if (grid_len(cmd) == 2) {
			name_or_value[1] = NULL;
			return (true);
		}
	}
	return (false);
}

bool set_var(shell_info_t *info, char **name_or_value)
{
	lnode_t *node = info->local_vars->head;
	var_t *var = NULL;

	while (node) {
		if (!strcmp(((var_t *)node->data)->name, name_or_value[0])) {
			free(((char *)((var_t *)node->data)->value));
			((var_t *)node->data)->value = name_or_value[1];
			return (true);
		}
		node = node->next;
	}
	var = init_struct_var(name_or_value[0], name_or_value[1]);
	if (!list_push_tail(var, info->local_vars)) {
		return (false);
	}
	return (true);
}

bool remove_var(shell_info_t *info, char **name_or_value)
{
	lnode_t *node = info->local_vars->head;
	var_t *var = NULL;

	while (node) {
		if (!strcmp(((var_t *)node->data)->name, name_or_value[0])) {
			list_pop(node, info->local_vars);
			return (true);
		}
		node = node->next;
	}
	return (false);
}
