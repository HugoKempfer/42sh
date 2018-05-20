/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** Init the shel info structure
*/

#include "42sh.h"
#include "shell_path.h"
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

shell_info_t *init_shell_info(char **base_env)
{
	shell_info_t *infos = malloc(sizeof(*infos));

	if (!(infos)) {
		return (NULL);
	}
	infos->processes = list_init(NULL);
	infos->global_vars = list_init(NULL);
	infos->local_vars = list_init(NULL);
	infos->env = init_list_env(base_env);
	if (!infos->env) {
		return (NULL);
	}
	infos->path = init_shell_path();
	if (infos->path) {
		return (NULL);
	}
	return (infos);
}
