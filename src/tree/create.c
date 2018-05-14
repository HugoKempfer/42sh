/*
** EPITECH PROJECT, 2018
** MiniShell
** File description:
** Create binary tree nodes
*/

#include "binary_tree.h"
#include "tools.h"
#include <stdbool.h>

tnode_t *create_tnode(tnode_data_t data)
{
	tnode_t *node = NULL;

	node = malloc(sizeof(*node));
	if (!(node)) {
		return (NULL);
	}
	node->right = NULL;
	node->left = NULL;
	node->data = data;
	return (node);
}

void add_link(tnode_t *parent, tnode_t *child, int position)
{
	if (!parent) {
		return;
	}
	if (position == LEFT) {
		parent->left = child;
	}
	else if (position == RIGHT) {
		parent->right = child;
	}
}

int create_and_link(tnode_t *parent, tnode_data_t data, int position)
{
	tnode_t *node = create_tnode(data);

	if (!(node) || !(parent)) {
		printf("Parent is [%p]\n", parent);
		free(node);
		return (false);
	}
	add_link(parent, node, position);
	return (true);
}
