/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** unsetenv functions
*/

#include "42sh.h"
#include "shell_path.h"
#include "str_manip.h"
#include "list.h"
#include "tools.h"
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int my_unsetenv(shell_info_t *infos, char **command)
{
	llist_t *env = infos->env;
	char *var_name = command[1];
	lnode_t *var = NULL;

	if (var_name == NULL) {
		fprintf(stderr, "unsetenv: Too few arguments.\n");
		return (false);
	}
	var = env_get_node(env, var_name);
	if (!var) {
		return (false);
	}
	if (var) {
		free(var->data);
		list_pop(var, env);
	}
	return (true);
}
