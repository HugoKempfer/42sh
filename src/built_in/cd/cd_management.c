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

static void print_var_paths(path_t *path, llist_t *env)
{
	lnode_t *node = NULL;

	printf("oldpwd : %s\n", path->oldpwd);
	printf("pwd : %s\n", path->pwd);
	printf("home : %s\n", path->home);
	node = env_get_node(env, "PWD=");
	if (node) {
		printf("env pwd : %s\n", (char*)node->data);
	}
	node = env_get_node(env, "OLDPWD=");
	if (node) {
		printf("env oldpwd : %s\n", (char*)node->data);
	}
	node = env_get_node(env, "HOME=");
	if (node) {
		printf("env home : %s\n", (char*)node->data);
	}
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

int cd_management(char **command, shell_info_t *shell)
{
	printf("ayooo\n");
	char *path = chdir_path(shell->env, shell->path, command[1]);
	if (chdir(path) != 0) {
		printf("chdir en NULL\n");
		return (false);
	}
	print_var_paths(shell->path, shell->env);
	if (!reset_paths_var(shell->path, shell->env)) {
		return (false);
	}
	printf("---------------------------------------\n"); 
	print_var_paths(shell->path, shell->env);
	printf("_____________\n"); 
	return (true);
}
