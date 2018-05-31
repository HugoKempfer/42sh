/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** change the reuturn code
*/

#include <stdio.h>
#include "42sh.h"
#include "var.h"

int create_or_set_var(lnode_t *node, char *name, char *val, shell_info_t *info);

void update_return_code(shell_info_t *infos, int code)
{
	char *buffer = malloc(50);

	sprintf(buffer, "%d", code);
	create_or_set_var(infos->local_vars->head, "?", buffer, infos);
}
