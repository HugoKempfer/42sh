/*
** EPITECH PROJECT, 2018
** cd_management.c
** File description:
** function_for_cd_management.c
*/

#include "42sh.h"
#include "shell_path.h"
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>

int reset_path_var_env(llist_t *env, char *name, char *path)
{
	lnode_t *var = NULL;
	char *var_path = NULL;
	char *var_name_env = str_concat((char*[]){name, "=", NULL});

	if (!var_name_env) {
		return (false);
	}
	var = env_get_node(env, var_name_env);
	if (var) {
		var_path = str_concat((char*[]){var_name_env, path, NULL});
		if (!var_path) {
			return (false);
		}
		var->data = var_path;
	}
	return (true);
}

int reset_paths_var(path_t *paths_var, llist_t *env)
{
	paths_var->oldpwd = strdup(paths_var->pwd);
	paths_var->pwd = getcwd(NULL, 0);
	if (!reset_path_var_env(env, "PWD", paths_var->pwd)) {
		return (false);
	}
	if (!reset_path_var_env(env, "OLDPWD", paths_var->oldpwd)) {
		return (false);
	}
	return (true);
}

void print_var_paths(path_t *path)
{
	printf("oldpwd : %s\n", path->oldpwd);
	printf("pwd : %s\n", path->pwd);
	printf("home : %s\n", path->home);
}

char *chdir_path(llist_t *env, path_t *paths_var, char *command)
{
	char *path = NULL;
	lnode_t *home_var = NULL;

	if (command == NULL || !strcmp(command, "~")) {
		home_var = env_get_node(env, "HOME=");
		path = (home_var) ? home_var->home : paths_var->home;
	} else {
		path = command;
	}
	return (path);
}

int cd_management(char **command, shell_info_t *shell)
{
	char *path = chdir_path(shell->env, shell->path, command[1]);;

	if (chdir(path) != 0) {
		return (false);
	}
	print_var_paths(shell->path);
	my_env(shell);
	printf("___________________________________________\n");
	reset_paths_var(shell->path, shell->env);
	print_var_paths(shell->path);
	my_env(shell);
	return (true);
}
