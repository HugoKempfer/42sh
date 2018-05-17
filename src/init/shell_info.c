/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** Init the shel info structure
*/

#include "list.h"
#include "42sh.h"
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void my_unsetenv(char **commande, shell_info_t *infos);

static shell_info_t *init_shell_info(void)
{
	shell_info_t *infos = malloc(sizeof(*infos));

	if (!(infos)) {
		return (NULL);
	}
	infos->processes = list_init(NULL);
	infos->global_vars = list_init(NULL);
	infos->local_vars = list_init(NULL);
	infos->env = list_init(NULL);
	return (infos);
}

shell_info_t *init_shell(char **base_env)
{
	shell_info_t *shell = init_shell_info();
	char **buffer = NULL;

	init_list(base_env, shell->env);
	my_env(shell);
	return (shell);
}
