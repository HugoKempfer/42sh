/*
** EPITECH PROJECT, 2018
** var_helpers.c
** File description:
** helpers for managing local/global shell variables
*/

#include "list.h"
#include "var.h"
#include "42sh.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

size_t grid_len(char **grid)
{
	size_t word_idx = 0;

	if (!grid) {
		return (0);
	}
	while (grid[word_idx++]);
	return (--word_idx);
}

int is_alpha_num(char *str)
{
	size_t idx = 0;

	while (str[idx]) {
		if (!isalnum(str[idx])) {
			return (false);
		}
		idx++;
	}
	return (true);
}

static int rm_if_found(lnode_t *node, char *name, shell_info_t *info)
{
	while (node) {
		if (!strcmp(((var_t *)node->data)->name, name)) {
			list_pop(node, info->local_vars);
			return (true);
		}
		node = node->next;
	}
	return (false);
}

int remove_var(shell_info_t *info, char **command)
{
	lnode_t *node = info->local_vars->head;
	var_t *var = NULL;
	char *name = NULL;

	if (!command) {
		return (false);
	}
	name = command[1];
	if (!strcmp(command[0], "unset") && grid_len(command) != 1) {
		if (rm_if_found(node, name, info)) {
			return (true);
		}
	}
	else if (!strcmp(command[0], "unset") && grid_len(command) == 1) {
		fprintf(stderr, "unset: Too few arguments.\n");
	}
	return (false);
}