/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** Management of the env variables
*/

#include "42sh.h"
#include "list.h"
#include <stdio.h>
#include <string.h>

char *env_get_var(shell_info_t *infos, char *var_name)
{
	lnode_t *node = infos->env->head;

	while (node) {
		if (!strcmp(var_name, node->data)) {
			return (node->data);
		}
		node = node->next;
	}
	return (NULL);
}

int env_push_var(char *var_name, shell_info_t *infos)
{
	char *var_str = env_get_var(infos, var_name);

	if (var_str) {
		
	}
}
