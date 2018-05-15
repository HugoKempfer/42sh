/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** Initialization of the env list
*/

#include "42sh.h"
#include "list.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

/* Example of the tcsh vars
	PWD=/home/hugo
	OLDPWD=/
	USER=hugo
	GROUP=users
	HOME=/home/
*/

static int copy_base_env(char **base_env, llist_t *env)
{
	lnode_t *var = env->head;

	while (*base_env) {
		if (!list_push_tail(*base_env, env)) {
			return (false);
		}
		++base_env;
	}
	return (true);
}

static int exist_var(llist_t *env, char *var_name)
{
	node_t *var = env->head;

	while (var) {
		if (!strncmp(var->data, var_name, my_strlen(var_name))) {
			return (true);
		}
		var = var->next;
	}
	return (false);
}

int push_variable_env(llist_t *env, char *name, char *var_value)
{
	char *variable = NULL;

	if (!exist_var(env, name)) {
		variable = str_concat((char *[]){name, "=", var_value});
		if (variable && !list_push_tail(variable, env)) {
			return (false);
		}
	}
	return (true);
}

int add_basic_variables_env(llist *env)
{
	struct passwd *pw = getpwuid(getuid());

	if (!push_variable_env(env, "USER", pw->pw_uid)) {
		return (false);
	}
	if (!push_variable_env(env, "HOME", pw->pw_dir)) {
		return (false);
	}
	if (!push_variable_env(env, "PATH", "/bin:/usr/bin:/usr/local/bin")) {
		return (false);
	}
	/*getcwd(NULL, un chiffre)*/
	return (true);
}

int init_list(char **base_env, llist_t *env)
{
	if (!copy_base_env(base_env, env)) {
		return (false);
	}
	if (!add_basic_variables_env(env)) {
		return (false);
	}
	return (true);
}
