/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** function to reset var path in path_var struct and in env
*/

#include "42sh.h"
#include "str_manip.h"
#include "shell_path.h"
#include "str_manip.h"
#include "tools.h"
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>

int reset_path_var_env(llist_t *env, char *var_name, char *var_path)
{
	lnode_t *var = NULL;
	char *new_var_path = NULL;

	var = env_get_node(env, var_name);
	if (var) {
		free(var->data);
		new_var_path = str_concat((char*[]){var_name, var_path, NULL});
		if (!new_var_path) {
			return (false);
		}
		var->data = new_var_path;
	}
	return (true);
}

int reset_paths_var(path_t *paths_var, llist_t *env)
{
	free(paths_var->oldpwd);
	paths_var->oldpwd = strdup(paths_var->pwd);
	free(paths_var->pwd);
	paths_var->pwd = getcwd(NULL, 0);
	if (!reset_path_var_env(env, "PWD=", paths_var->pwd)) {
		return (false);
	}
	if (!reset_path_var_env(env, "OLDPWD=", paths_var->oldpwd)) {
		return (false);
	}
	return (true);
}
