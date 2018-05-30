/*
** EPITECH PROJECT, 2018
** cd_management.c
** File description:
** function_for_cd_management.c
*/

#include "42sh.h"
#include "str_manip.h"
#include "shell_path.h"
#include <errno.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>

static int reset_path_var_env(llist_t *env, char *var_name, char *var_path)
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

static int reset_paths_var(path_t *paths_var, llist_t *env)
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

static char *chdir_path(llist_t *env, path_t *paths_var, char *command)
{
	char *path = NULL;
	lnode_t *home_var = NULL;

	if (command == NULL || !strcmp(command, "~")) {
		home_var = env_get_node(env, "HOME=");
		if (home_var) {
			path = (char*)home_var->data + strlen("HOME=");
		} else {
			path = paths_var->home;
		}
	}
	else if (!strcmp(command, "-")) {
		path = paths_var->oldpwd;
	} else {
		path = command;
	}
	return (path);
}

int cd_management(shell_info_t *shell, char **command)
{
	char *path = chdir_path(shell->env, shell->path, command[1]);
	int chdir_value = chdir(path);

	if (chdir_value == -1 && errno == ENOENT) {
		fprintf(stderr, "%s: Aucun fichier ou dossier de ce type.\n",
			command[1]);
		return (false);
	}
	if (chdir_value == -1) {
		fprintf(stderr, "%s: N'est pas un dossier.\n", command[1]);
		return (false);
	}
	if (!reset_paths_var(shell->path, shell->env)) {
		return (false);
	}
	return (true);
}
