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

int add_alias(char **tab, shell_info_t *infos)
{
	llist_t *alias = infos->alias;
	int len = size_dbl_tab(tab);
	lnode_t *node = NULL;

	if (len < 3) {
		return (false);
	}
	node = get_the_node(alias, tab[1]);
	if (!node){
		create_new_alias(alias, tab);
	}
	else {
		((alias_t *)(node->data))->value = tab[2];
	}
	return (true);
}
