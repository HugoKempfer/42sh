/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** Management of the env variables
*/

#include "42sh.h"
#include "str_manip.h"
#include "list.h"
#include "tools.h"
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

lnode_t *env_get_node(llist_t *env, char *var_name)
{
	lnode_t *node = env->head;
	char *string = NULL;

	while (node) {
		string = node->data;
		if (!strncmp(string, var_name, strlen(var_name))) {
			return (node);
		}
		node = node->next;
	}
	return (NULL);
}

char *env_get_value(llist_t *env, char *var_name)
{
	lnode_t *node = env_get_node(env, var_name);

	if (!node) {
		return (NULL);
	}
	return ((char *)(node->data) + (strlen(var_name) + 1));
}

int my_env(shell_info_t *infos, char **command)
{
	int nb_args = size_dbl_tab(command);
	llist_t *env = infos->env;
	lnode_t *node = env->head;

	if (nb_args > 1) {
		fprintf(stderr, "env: « %s »: "
		"No such file or directory\n", command[1]);
		return (false);
	}
	while (node) {
		puts((char *)node->data);
		node = node->next;
	}
	return (true);
}
