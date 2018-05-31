/*
** EPITECH PROJECT, 2018
** add_alias.c
** File description:
** add_alias.c
*/

#include "42sh.h"
#include "list.h"
#include "alias.h"
#include "my.h"

lnode_t *get_alias_node(llist_t *alias, char *str)
{
	lnode_t *node = alias->head;

	while (node) {
		if (!strcmp(str, ((alias_t *)(node->data))->name)) {
			return (node);
		}
		node = node->next;
	}
	return (NULL);
}

int create_new_alias(llist_t *alias, char **tab)
{
	alias_t *fill_alias = malloc(sizeof(alias_t));

	if (!fill_alias) {
		return (false);
	}
	fill_alias->name = tab[1];
	fill_alias->value = tab[2];
	if (!list_push_tail(fill_alias, alias)) {
		return (false);
	}
	return (true);
}

char *get_new_value(llist_t *alias, char *value)
{
	lnode_t *node = alias->head;

	while (node) {
		if (!strcmp(value, ((alias_t *)(node->data))->name)) {
			return (((alias_t *)(node->data))->value);
		}
		node = node->next;
	}
	return (NULL);
}

int check_new_value(llist_t *alias, char *value)
{
	lnode_t *node = alias->tail;
	char *new_value = get_new_value(alias, value);

	if (new_value) {
		((alias_t *)(node->data))->value = new_value;
	}
	free(new_value);
	free(value);
	return (true);
}

int add_alias(shell_info_t *infos, char **tab)
{
	llist_t *alias = infos->alias;
	int len = size_dbl_tab(tab);
	lnode_t *node = NULL;

	if (len < 3) {
		return (false);
	}
	node = get_alias_node(alias, tab[1]);
	if (!node){
		create_new_alias(alias, tab);
		check_new_value(alias, ((alias_t *)(node->data))->value);
	}
	else {
		((alias_t *)(node->data))->value = tab[2];
	}
	return (true);
}
