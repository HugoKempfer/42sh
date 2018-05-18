/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** Management of the env variables
*/

#include "42sh.h"
#include "list.h"
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

char *str_concat(char **);
int my_putstr(char const *str);

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

void my_unsetenv(char **commande, shell_info_t *infos)
{
	llist_t *env = infos->env;
	char *var_name = commande[1];
	lnode_t *var = env_get_node(env, var_name);

	if (var) {
		list_pop(var, env);
	}
}

int my_setenv(char **commande, shell_info_t *infos)
{
	llist_t *env = infos->env;
	char *var_name = commande[1];
	char *var_value = commande[2];
	lnode_t *node = env_get_node(env, var_name);
	char *var = str_concat((char *[]){var_name, "=", var_value, NULL});

	if (!var) {
		return (false);
	}
	if (node) {
		node->data = var;
	} else {
		if (!list_push_tail(var, env)) {
			return (false);
		}
	}
	return (true);
}

int my_env(shell_info_t *infos)
{
	llist_t *env = infos->env;
	lnode_t *node = env->head;

	while (node) {
		my_putstr(node->data);
		write(1, "\n", 1);
		node = node->next;
	}
}
