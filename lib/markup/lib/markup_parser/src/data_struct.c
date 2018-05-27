/*
** EPITECH PROJECT, 2017
** data_struct.c
** File description:
** Function to handle the data struct creation
*/

#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include "markup.h"

static int allocate_data(mnode_t *node, char *label, char *value)
{
	if (node->type == CHILD) {
		node->data.child = malloc(sizeof(mchild_t));
		if (!(node->data.child)) {
			return (false);
		}
		node->data.child->value = value;
	} else {
		node->data.root = malloc(sizeof(mroot_t));
		if (!(node->data.root)) {
			return (false);
		}
		node->data.root->nb_nodes = 0;
		node->data.root->head = NULL;
		node->data.root->tail = NULL;
	}
	node->label = label;
	return (true);
}

mnode_t *create_node(char *label, char *value)
{
	mnode_t *node = malloc(sizeof(mnode_t));

	if (!(node)) {
		return (NULL);
	}
	node->type = value != NULL ? CHILD : ROOT;
	node->next = NULL;
	node->prev = NULL;
	if (!(allocate_data(node, label, value))) {
		return (NULL);
	}
	return (node);
}

mnode_t *insert_node_tail(char *label, char *value, mnode_t *root)
{
	mnode_t *node = create_node(label, value);

	if (!(node)) {
		return (NULL);
	} else if (root->type != ROOT) {
		return (NULL);
	}
	if (!(root->data.root->tail)) {
		root->data.root->head = node;
		root->data.root->tail = node;
	} else {
		root->data.root->tail->next = node;
		node->prev = root->data.root->tail;
		root->data.root->tail = node;
	}
	++(root->data.root->nb_nodes);
	return (node);
}

mnode_t *insert_node_head(char *label, char *value, mnode_t *root)
{
	mnode_t *node = create_node(label, value);

	if (!(node)) {
		return (NULL);
	} else if (root->type != ROOT) {
		return (NULL);
	}
	if (!(root->data.root->head)) {
		root->data.root->head = node;
		root->data.root->tail = node;
	} else {
		root->data.root->head->prev = node;
		node->next = root->data.root->head;
		root->data.root->head = node;
	}
	++(root->data.root->nb_nodes);
	return (node);
}
