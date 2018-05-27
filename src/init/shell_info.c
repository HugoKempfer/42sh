/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** Init the shel info structure
*/

#include "42sh.h"
#include "shell_path.h"
#include "alias.h"
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

alias_t *init_alias(char *name, char *value)
{
	alias_t *alias = malloc(sizeof(alias_t) * 1);
	printf("NAMMMMMMMMMMME : %s\n", name);
	alias->name = strdup(name);
	alias->value = strdup(value);
	return (alias);
}

shell_info_t *init_shell_info(char **base_env)
{
	shell_info_t *infos = malloc(sizeof(*infos));

	if (!(infos)) {
		return (NULL);
	}
	infos->processes = list_init(NULL);
	infos->special_vars = list_init(NULL);
	infos->local_vars = list_init(NULL);
	infos->env = init_list_env(base_env);
	infos->alias = list_init(NULL);
	list_push_tail(init_alias("HUGO", "PD"), infos->alias);
	list_push_tail(init_alias("JORDAN", "ENCULE"), infos->alias);
	list_push_tail(init_alias("FANFAN", "TEUTEU"), infos->alias);
	if (!infos->env) {
		return (NULL);
	}
	infos->path = init_shell_path();
	if (!infos->path) {
		return (NULL);
	}
	return (infos);
}
