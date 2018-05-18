/*
** EPITECH PROJECT, 2018
** change_var_cd.c
** File description:
** change_var_cd.c
*/

#include "42sh.h"
#include "shell_path.h"
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include <pwd.h>

void change_old_pwd_var(shell_path_t *cd_path, llist_t *env)
{
	lnode_t *var = env_get_node(env, "OLD_PWD");
	char *var_name = cd_path->pwd;

	if (var) {
		var->data = var_name;
	}
	cd_path->old_pwd = var_name;
}

int change_pwd_var(shell_path_t *cd_path, llist_t *env)
{
	lnode_t *var = env_get_node(env, "PWD");
	char *var_name = str_concat((char *[]){"PWD=", getcwd(NULL, 4096)});

	if (!var_name) {
		return (false);
	}
	if (var) {
		var->data = var_name;
	}
	cd_path->pwd = var_name;
	return (true);
}

int change_home_var(shell_path_t *cd_path, llist_t *env)
{
	struct passwd *pw = getpwuid(getuid());
	lnode_t *var = NULL;
	char *var_name = NULL;

	if (!pw) {
		return (false);
	}
	var_name = str_concat((char *[]){"OLDPWD42=", (char *)pw->pw_dir});
	if (!var_name) {
		return (false);
	}
	var = env_get_node(env, "OLDPWD");
	if (var) {
		var->data = var_name;
	}
	cd_path->pwd = var_name;
	return (true);
}

int change_var_env(shell_path_t *cd_path, llist_t *env)
{
	change_old_pwd_var(cd_path, env);
	if (!change_pwd_var(cd_path, env)) {
		return (false);
	}
	if (!change_home_var(cd_path, env)) {
		return (false);
	}
	return (true);
}
