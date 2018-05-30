/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** setenv functions
*/

#include "42sh.h"
#include "shell_path.h"
#include "str_manip.h"
#include "list.h"
#include "tools.h"
#include <unistd.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

static int isalnum_string(char *str)
{
	while (*str) {
		if (!isalnum(*str)) {
			return (false);
		}
		++(str);
	}
	return (true);
}

static int error_gestion(char *first_arg)
{
	if (!isalpha(*first_arg) || !isalnum_string(first_arg + 1)) {
		return (false);
	}
	return (true);
}

static int do_setenv(shell_info_t *infos, char **command)
{
	llist_t *env = infos->env;
	char *var_name = command[1];
	char *var_value = command[2];
	lnode_t *node = env_get_node(env, var_name);
	char *var = str_concat((char *[]){var_name, "=", var_value, NULL});

	if (!var || !error_gestion(var_name)) {
		return (false);
	}
	if (!strcmp(var_name, "HOME")) {
		infos->path->home = var + strlen("HOME=");
	}
	if (node) {
		node->data = var;
	} else {
		if (!list_push_tail(var, env)) {
			return (false);
		}
	}
	return (true);
}

int my_setenv(shell_info_t *infos, char **command)
{
	int nb_args = size_dbl_tab(command);

	if (nb_args >= 4) {
		fprintf(stderr, "setenv: Too many arguments.\n");
		return (false);
	} else if (nb_args > 1) {
		return (do_setenv(infos, command));
	} else if (nb_args == 1) {
		return (my_env(infos, command));
	}
}
