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
int cd_management(char **command, shell_info_t *infos);

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
	infos->path = init_shell_path();
	cd_management((char*[]){"cd", "../../~//.."}, infos);
	return (infos);
}
