/*
** EPITECH PROJECT, 2017
** tree_explorer.c
** File description:
** Functions to retrieve/add/remove data from the tree
*/

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <markup.h>
#include "libstring.h"

//Search in a tree a given node's label. Format label = "root/foo1/foo2"
mnode_t *get_node(char *label, mnode_t *root)
{
	int it = get_next_occur(label, '/');
	char *token = NULL;
	mnode_t *temp = NULL;

	if (!it || !root) {
		return (root);
	}
	if (root && root->type == ROOT) {
		temp = root->data.root->head;
	}
	token = alloc_str(label, it);
	while (temp && my_strcmp(token, temp->label)) {
		temp = temp->next;
	}
	free(token);
	return (get_node(&label[it + 1], temp));
}

char *get_value(char *label, mnode_t *root)
{
	mnode_t *node = get_node(label, root);

	if (node && node->type == CHILD) {
		return (node->data.child->value);
	}
	return (NULL);
}
