/*
** EPITECH PROJECT, 2017
** tree_free.c
** File description:
** Functions to free the markup data structure
*/

#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>
#include "markup.h"

static int free_node(mnode_t *node)
{
	if (!(node)) {
		return (false);
	}
	if (node->type == CHILD) {
		if (node->data.child) {
			free(node->data.child->value);
			free(node->data.child);
		}
	}
	else {
		if (node->data.root) {
			free(node->data.root);
		}
	}
	free(node->label);
	free(node);
	return (true);
}

int delete_node(mnode_t *node, mnode_t *root)
{
	int state = 0;

	if (!(node->next) && !(node->prev)) {
		root->data.root->head = NULL;
		root->data.root->tail = NULL;
	} else if (!(node->next) || !(node->prev)) {
		if (!(node->next) && node->prev) {
			node->prev->next = node->next;
			root->data.root->tail = node->prev;
		} else if (!(node->prev) && node->next) {
			node->next->prev = node->prev;
			root->data.root->head = node->next;
		}
	} else {
		node->prev->next = node->next;
		node->next->prev = node->prev;
	}
	state = root->data.root->nb_nodes ? free_node(node) : 0;
	root->data.root->nb_nodes -= 1;
	return (state);
}

static int destroy_sub_branches(mnode_t *root)
{
	mnode_t *node = root->data.root->head;
	mnode_t *temp = NULL;

	if (!(node)) {
		return (false);
	}
	while (node) {
		temp = node;
		if (node->type == ROOT) {
			destroy_sub_branches(node);
		}
		node = node->next;
		delete_node(temp, root);
	}
	return (true);
}

int destroy_tree(mnode_t *root)
{
	if (!(root) || !(destroy_sub_branches(root))) {
		return (false);
	}
	free(root->data.root);
	free(root);
	return (true);
}
