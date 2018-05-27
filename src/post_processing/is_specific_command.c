/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** is specific command ? specific commands are backticks, alias, variable,
** globings, " ", ' '.
*/

#include "42sh.h"
#include "list.h"
#include "metadata.h"
#include "tools.h"
#include "post_processing.h"
#include "alias.h"
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>

int is_alias(shell_info_t *infos, char *lexem)
{
	llist_t *alias_list = infos->alias;
	lnode_t *alias_node = alias_list->head;

	while (alias_node) {
		if (!strcmp(((alias_t *)(alias_node->data))->name, lexem)) {
			return (true);
		}
		alias_node = alias_node->next;
	}
	return (false);
}

int is_globings(unused shell_info_t *infos, char *lexem)
{
	while (*lexem) {
		if (*lexem == '*' || *lexem == '?') {
			return (true);
		}
		if (*lexem == '['
		&& strlen(lexem) >= 4  && *(lexem + 4) == ']') {
			return (true);
		}
		++(lexem);
	}
	return (false);
}
