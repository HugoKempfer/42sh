/*
** EPITECH PROJECT, 2018
** print_alias_value.c
** File description:
** print_alias_value.c
*/

#include "42sh.h"
#include "list.h"
#include "alias.h"
#include "my.h"

int print_value(llist_t *alias, char *name)
{
	lnode_t *node = get_alias_node(alias, name);

	if (!node) {
		return (false);
	}
	printf("%s\n", ((alias_t *)(node->data))->value);
	return (true);
}
