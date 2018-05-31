/*
** EPITECH PROJECT, 2018
** set_var.c
** File description:
** set var builtin
*/

#include "list.h"
#include "var.h"
#include "42sh.h"
#include <ctype.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

void print_the_list(shell_info_t *info)
{
	lnode_t *tmp_node = info->local_vars->head;

	while (tmp_node) {
		printf("%s", ((var_t *)tmp_node->data)->name);
		if (((var_t *)tmp_node->data)->value) {
			putchar('\t');
			printf("%s", (((var_t *)tmp_node->data)->value));
		}
		putchar('\n');
		tmp_node = tmp_node->next;
	}
}

static int format_checker(char **cmd)
{
	if (!isalpha(cmd[1][0]) || (grid_len(cmd) > 2 && !isalpha(cmd[2][0]) \
	&& cmd[2][0] != '=')) {
		fprintf(stderr, "set: Variable name must begin with"
		" a letter.\n");
	}
	else if (!is_alpha_num(cmd[1]) || (grid_len(cmd) > 2 && \
	!is_alpha_num(cmd[2]) && cmd[2][0] != '=')) {
		fprintf(stderr, "set: Variable name must contain");
		fprintf(stderr, " alphanumeric characters\n");
	}
	else {
		return (true);
	}
	return (false);
}

int is_setting_the_var(char **cmd, char **value, shell_info_t *info)
{
	if (!strcmp(cmd[0], "set") && grid_len(cmd) >= 2) {
		if (grid_len(cmd) >= 4 && !strcmp(cmd[2], "=")) {
			*value = cmd[3];
			return (format_checker(cmd));
		}
		else if (grid_len(cmd) == 2) {
			*value = NULL;
			return (format_checker(cmd));
		}
		else {
			return (format_checker(cmd));
		}
	}
	else if (!strcmp(cmd[0], "set") && grid_len(cmd) == 1) {
		print_the_list(info);
	}
	return (false);
}

int create_or_set_var(lnode_t *node, char *name, char *val, shell_info_t *info)
{
	var_t *var = NULL;

	while (node) {
		if (!strcmp(((var_t *)node->data)->name, name)) {
			free(((char *)((var_t *)node->data)->value));
			((var_t *)node->data)->value = val;
			return (true);
		}
		node = node->next;
	}
	var = init_struct_var(name, val);
	if (!list_push_tail(var, info->local_vars)) {
		return (false);
	}
	return (true);
}

int set_var(shell_info_t *info, char **command)
{
	lnode_t *node = info->local_vars->head;
	char *name = NULL;
	char *value = NULL;

	if (!command) {
		return (false);
	}
	name = command[1];
	if (is_setting_the_var(command, &value, info)) {
		if (!create_or_set_var(node, name, value, info)) {
			return (false);
		}
		return (true);
	}
	return (false);
}
