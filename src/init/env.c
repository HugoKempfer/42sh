/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** Initialization of the env list
*/

#include "42sh.h"
#include "shell_path.h"
#include "list.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>

char *str_concat(char **);

static int copy_base_env(char **base_env, llist_t *env)
{
	if (!base_env || !base_env[0]) {
		return (true);
	}
	while (*base_env) {
		if (!list_push_tail(*base_env, env)) {
			return (false);
		}
		++base_env;
	}
	return (true);
}

int exist_var(llist_t *env, char *var_name)
{
	lnode_t *var = env->head;
	char *string = NULL;

	while (var) {
		string = var->data;
		if (!strncmp(string, var_name, strlen(var_name))) {
			return (true);
		}
		var = var->next;
	}
	return (false);
}

static int push_variable_env(llist_t *env, char *name, char *var_value)
{
	char *variable = NULL;

	if (!exist_var(env, name)) {
		variable = str_concat((char *[]){name, "=", var_value, NULL});
		if (variable && !list_push_tail(variable, env)) {
			return (false);
		}
	}
	return (true);
}

static int add_basic_variables_env(llist_t *env)
{
	struct passwd *pw = getpwuid(getuid());
	char *pwd = NULL;

	if (!push_variable_env(env, "USER", (char *)pw->pw_name)) {
		return (false);
	}
	if (!push_variable_env(env, "HOME", (char *)pw->pw_dir)) {
		return (false);
	}
	if (!push_variable_env(env, "PATH", "/bin:/usr/bin:/usr/local/bin")) {
		return (false);
	}
	if (!push_variable_env(env, "PWD", getcwd(pwd, 30))) {
		return (false);
	}
	return (true);
}

llist_t *init_list_env(char **base_env)
{
	llist_t *env = list_init(NULL);

	if (!copy_base_env(base_env, env)) {
		return (NULL);
	}
	if (!add_basic_variables_env(env)) {
		return (NULL);
	}
	return (env);
}
