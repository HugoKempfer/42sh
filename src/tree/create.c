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
	node->data = data;
	return (node);
}

int add_link(tnode_t *parent, tnode_t *child, int position)
{
	tnode_t *branch = position == LEFT ? parent->left : parent->right;
	int state = !(branch) ? NOT_EXISTING : EXISTING;

	if (!(parent)) {
		return (false);
	}
	branch = child;
	return (state);
}

int create_and_link(tnode_t *parent, tnode_data_t data, int position)
{
	int state = 0;
	tnode_t *node = create_tnode(data);

	if (!(node)) {
		return (false);
	}
	state = add_link(parent, node, position);
	return (state);
}
