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

shell_info_t *init_shell_info(void)
{
	shell_info_t *infos = malloc(sizeof(*infos));

	if (!(infos)) {
		return (NULL);
	}
	infos->processes = list_init(NULL);
	infos->special_vars = list_init(NULL);
	infos->local_vars = list_init(NULL);
	infos->env = list_init(NULL);
	return (infos);
}
