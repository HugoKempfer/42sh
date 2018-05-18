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

/*change init structure and env*/
static char SEPARATORS[] = {
	'/',
	'\0',
	'\n',
	-1
};

static char SENTINEL_CHAR[] = {
	-1
};

static char *SUROUNDINGS[] = {
	NULL
};

void print_dbl_tab(char **str)
{
	while (*str) {
		printf("case : %s\n", *str);
		++(str);
	}
}

int cd_home(shell_path_t *cd_path, llist_t *env)
{
	lnode_t *var = env_get_node(env, "HOME");
	char *var_string = var->data;

	if (var) {
		if (!chdir(var_string + (strlen("HOME") + 1))) {
			return (false);
		}
	} else {
		if (!chdir(cd_path->home)) {
			return (false);
		}
	}
	cd_path->old_pwd = strdup(cd_path->pwd);
	cd_path->pwd = cd_path->home;
	return (true);
}

int cd_previous(shell_path_t *cd_path)
{
	if (!chdir(cd_path->old_pwd)) {
		return (false);
	}
	cd_path->old_pwd = strdup(cd_path->pwd);
	cd_path->pwd = cd_path->old_pwd;
	return (true);
}

int size_back_dir_path(shell_path_t *cd_path)
{
	char *pwd_path = cd_path->pwd;
	int size_path = 0;
	int size_way_deleted = 0;

	while (*pwd_path) {
		++(pwd_path);
		++size_path;
	}
	--(pwd_path);
	while (*pwd_path != '/') {
		++size_way_deleted;
		--(pwd_path);
	}
	return (size_path - size_way_deleted - 1);
}

int cd_back_parent_dir(shell_path_t *cd_path)
{
	char *back_path = cd_path->pwd;
	char *path_chdir = strndup(back_path, size_back_dir_path(cd_path));
	printf("back path : %s\n", path_chdir);
	if (!path_chdir) {
		return (false);
	}
	if (!chdir(path_chdir)) {
		return (false);
	}
	cd_path->old_pwd = strdup(cd_path->pwd);
	cd_path->pwd = path_chdir;
	return (true);
}

int execute_cd(shell_path_t *cd_path, llist_t *env, char *command)
{
	if (!strcmp(command, "~")) {
		return (cd_home(cd_path, env));
	}
	if (!strcmp(command, "-")) {
		return (cd_previous(cd_path));
	}
	if (!strcmp(command, "..")) {
		return (cd_back_parent_dir(cd_path));
	}
	return (true);
}

int cd_management(char **command, shell_info_t *shell)
{
	const cutter_charset_t cutter = {SEPARATORS, SENTINEL_CHAR, SUROUNDINGS};
	char **cd_args = subdivise_str(command[1], cutter);

	if (command[0] == NULL) {
		if (!cd_home(shell->path, shell->env)) {
			return (false);
		}
		return (true);
	}
	while (*cd_args) {
		printf("%s\n", *cd_args);
		if (!execute_cd(shell->path, shell->env, *cd_args)) {
			printf("return false 1\n");
			return (false);
		}
/*		if (!change_var_env(shell->path, shell->env)) {
			printf("return false 2\n");
			return (false);
			}*/
		++(cd_args);
	}
	return (true);
}
