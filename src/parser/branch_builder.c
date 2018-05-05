/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** Functions to build the tree branches
*/

#include "binary_tree.h"
#include "list.h"
#include "lexer.h"
#include "parser.h"
#include "42sh.h"
#include "tools.h"

static int push_tnode(token_t *token, tnode_t *head, int position)
{
	tnode_data_t data = {token->type, token->value};

	if (!(create_and_link(head, data, position))) {
		return (false);
	}
	return (true);
}

static inline int is_last_command(lnode_t *node)
{
	token_t *token = NULL;

	if (!node) {
		return (true);
	}
	token = node->data;
	if (IS_TREE_SEPARATOR(token->type)) {
		return (true);
	}
	return (false);
}

/* Build the main branches which hold expressions together */
int build_separator_branch(llist_t *tokens, tnode_t *head)
{
	lnode_t *node = tokens->tail;
	token_t *token = NULL;

	if (!node) {
		return (false);
	}
	do {
		token = node->data;
		if (token->type == COMMAND) {
			node = node->prev;
			continue;
		}
		if (!(push_tnode(token, head, LEFT))) {
			return (false);
		}
		head = head->left;
		node = node->prev;
		list_pop(node->next, tokens);
	} while (node && !(IS_TREE_SEPARATOR(token->type)));
	return (true);
}

/* Build ann sub-branches which heritates from the separators branches */
int add_expressions_branch(llist_t *tokens, tnode_t *head)
{
	lnode_t *node = tokens->tail;
	token_t *token = NULL;
	int position;

	if (!(node)) {
		return (false);
	}
	do {
		token = node->data;
		position = is_last_command(node->prev) ? LEFT : RIGHT;
		if (!push_tnode(token, head, position)) {
			return (false);
		}
		node = node->prev;
		head = head->left;
		list_pop(node, tokens);
	} while (node && token->type == COMMAND);
	return (true);
}
