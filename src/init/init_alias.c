/*
** EPITECH PROJECT, 2018
** init_alias.c
** File description:
** init_alias.c
*/

#include "markup.h"
#include "42sh.h"
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

mnode_t *parse_file(char *filepath);

llist_t *init_alias(void)
{
	llist_t *alias = list_init(NULL);
	mnode_t *root = parse_file("./42shrc");
	mnode_t *node = get_node("alias/", root)->data.root->head;
	if (!node) {
		printf("zbeub\n");
	}
	while (node) {
		printf("-----------------\n");
		printf("Label [%s]\n", node->label);
		printf("Value [%s]\n", node->data.child->value);
		node = node->next;
	}
	destroy_tree(root);
	return (alias);
}
