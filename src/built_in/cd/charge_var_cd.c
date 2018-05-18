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
	lnode_t *var = env_get_node(env, "OLDPWD");
	char *var_name = str_concat((char *[]){"OLDPWD=", cd_path->pwd, NULL});

	if (var) {
		var->data = var_name;
	}
	cd_path->old_pwd = var_name + strlen("OLDPWD=");
}

int change_pwd_var(shell_path_t *cd_path, llist_t *env)
{
	lnode_t *var = env_get_node(env, "PWD");
	char *var_name = str_concat((char *[]){"PWD=", getcwd(NULL, 4096), NULL});
	printf("getcwd new pwd path : %s\n", getcwd(NULL, 4096));
	if (!var_name) {
		return (false);
	}
	if (var) {
		var->data = var_name;
	}
	cd_path->pwd = var_name + strlen("PWD=") + 1;
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
	var_name = str_concat((char *[]){"HOME=", (char *)pw->pw_dir});
	if (!var_name) {
		return (false);
	}
	var = env_get_node(env, "HOME");
	if (var) {
		var->data = var_name;
	}
	cd_path->home = var_name + strlen("HOME=") + 1;
	return (true);
}

int change_var_env(shell_path_t *cd_path, llist_t *env)
{
	printf("pwd : %s\n", cd_path->pwd);
	printf("old_pwd : %s\n", cd_path->old_pwd);
	printf("home : %s\n", cd_path->home);
	printf("-----------------------------------\n");
	return (true);
}
