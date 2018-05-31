/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** Init the shel info structure
*/

#include "shell_path.h"
#include "alias.h"
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

llist_t *init_alias(llist_t *alias);

shell_info_t *init_shell_info(char **base_env)
{
	shell_info_t *infos = malloc(sizeof(*infos));

	if (!(infos))
		return (NULL);
	infos->processes = list_init(NULL);
	infos->special_vars = list_init(NULL);
	infos->local_vars = list_init(NULL);
	infos->history = list_init(NULL);
	infos->env = init_list_env(base_env);
	if (!infos->env)
		return (NULL);
	infos->path = init_shell_path();
	if (!infos->path)
		return (NULL);
	infos->alias = list_init(NULL);
	infos->alias = init_alias(infos->alias);
	if (!infos->alias)
		return (NULL);
	return (infos);
}
