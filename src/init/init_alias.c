/*
** EPITECH PROJECT, 2018
** init_alias.c
** File description:
** init_alias.c
*/

#include "markup.h"
#include "alias.h"
#include "42sh.h"

mnode_t *parse_file(char *filepath);

int fill_list_alias(llist_t *alias, mnode_t *node)
{
	alias_t *fill_alias = malloc(sizeof(alias_t));

	if (!fill_alias) {
		return (false);
	}
	fill_alias->name = node->label;
	fill_alias->value = node->data.child->value;
	if (!list_push_tail(fill_alias, alias)) {
		return (false);
	}
	return (true);
}

llist_t *init_alias(void)
{
	llist_t *alias = list_init(NULL);
	mnode_t *root = parse_file("42shrc");
	mnode_t *node;
	int check = 0;

	if (!root || !alias) {
		return (NULL);
	}
	node = get_node("alias/", root)->data.root->head;
	while (node) {
		check = fill_list_alias(alias, node);
		if (!check) {
			return (NULL);
		}
		node = node->next;
	}
	destroy_tree(root);
	free(node);
	return (alias);
}
