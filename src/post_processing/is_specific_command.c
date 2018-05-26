/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** is specific command ? specific commands are backticks, alias, variable,
** globings, " ", ' '.
*/

#include "42sh.h"
#include "metadata.h"
#include "tools.h"
#include "post_processing.h"
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
/*
int is_alias(shell_info_t *infos, char *lexem)
{
	llist_t *alias_list = infos->alias;
	lnode_t *alias_node = alias_list->head;

	while (alias_node) {
		if (!strcmp(alias_node->data->name, lexem)) {
			return (true);
		}
		alias_node = alias_node->next;
	}
	return (false);
}

int is_variable(shell_info_t *infos, char *lexem)
{
	llist_t *var_list = infos->local_vars;
	lnode_t *var_node = var_list->head;

	while (var_node) {
		if (!strcmp(var_node->data->name, lexem)) {
			return (true);
		}
		var_node = var_node->next;
	}
	return (false);
	}*/
int is_globings(unused shell_info_t *infos, char *lexem)
{
	while (*lexem) {
		if (*lexem == '*' || *lexem == '?') {
			return (true);
		}
		if (*lexem == '[' && *(lexem + 4) == ']') {
			return (true);
		}
	}
	return (false);
}

int is_surrondings(char *str, char c)
{
	if (*str == c && *(str + strlen(str) - 1) == c) {
		return (true);
	}
	return (false);
}

int is_double_coat(unused shell_info_t *infos, char *lexem)
{
	if (is_surrondings(lexem, '"')) {
		return (true);
	}
	return (false);
}

int is_simple_coat(unused shell_info_t *infos, char *lexem)
{
	if (is_surrondings(lexem, '\'')) {
		return (true);
	}
	return (false);

}

int is_backticks(unused shell_info_t *infos, char *lexem)
{
	if (is_surrondings(lexem, '`')) {
		return (true);
	}
	return (false);
}
