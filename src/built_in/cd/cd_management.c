/*
** EPITECH PROJECT, 2018
** cd_management.c
** File description:
** function_for_cd_management.c
*/

#include "42sh.h"
#include "str_manip.h"
#include "shell_path.h"
#include "str_manip.h"
#include "tools.h"
#include <errno.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>


static char *get_path_home(llist_t *env, path_t *paths_var, char *cmd)
{
	lnode_t *home_var = NULL;
	char *path = NULL;

	home_var = env_get_node(env, "HOME=");
	if (home_var) {
		path = (char*)home_var->data + strlen("HOME=");
	} else {
		path = paths_var->home;
	}
	if (cmd) {
		path = str_concat((char *[]){paths_var->home, cmd + 1, NULL});
		if (!path) {
			return (false);
		}
	}
	return (path);
}

static char *chdir_path(llist_t *env, path_t *paths_var, char *command)
{
	char *path = NULL;

	if (command == NULL || command[0] == '~') {
		path = get_path_home(env, paths_var, command);
		if (!path) {
			return (false);
		}
	}
	else if (!strcmp(command, "-")) {
		path = paths_var->oldpwd;
	} else {
		path = command;
	}
	return (path);
}

int error_gestion(int chdir_value, char **command)
{
	if (size_dbl_tab(command) > 2) {
		fprintf(stderr, "cd: Too many arguments.\n");
		return (false);
	}
	if (chdir_value == -1 && errno == ENOENT) {
		fprintf(stderr, "%s: No such file or directory.\n",
			command[1]);
		return (false);
	}
	if (chdir_value == -1) {
		fprintf(stderr, "%s: Not a directory.\n", command[1]);
		return (false);
	}
	return (true);
}

int cd_management(shell_info_t *shell, char **command)
{
	char *path = chdir_path(shell->env, shell->path, command[1]);
	int chdir_value = chdir(path);

	if (!error_gestion(chdir_value, command)) {
		return (false);
	}
	if (!reset_paths_var(shell->path, shell->env)) {
		return (false);
	}
	return (true);
}
