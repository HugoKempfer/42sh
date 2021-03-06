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

int push_tnode(token_t *token, tnode_t *head, int position);

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

int add_autonomous_cmd(tnode_t *head, llist_t *tokens)
{
	if (!(push_tnode(((token_t *)(tokens->tail->data)), head, LEFT))) {
		return (false);
	}
	list_pop(tokens->tail, tokens);
	return (true);
}

int build_separator_branch(llist_t *tokens, tnode_t *head)
{
	lnode_t *node = tokens->tail;

	if (!node) {
		return (false);
	}
	while (node && !(IS_TREE_SEPARATOR(((token_t *)(node->data))->type))) {
		if (((token_t *)(node->data))->type == COMMAND) {
			node = node->prev;
			continue;
		}
		if (!(push_tnode(node->data, head, LEFT))) {
			return (false);
		}
		head = head->left;
		node = node->prev;
		list_pop(node->next, tokens);
	}
	return (true);
}

static int is_tree_last_expression(lnode_t *node)
{
	if (!node) {
		return (true);
	}
	else if (IS_TREE_SEPARATOR(((token_t *)(node->data))->type)) {
		return (true);
	}
	return (false);
}

/* Build ann sub-branches which heritates from the separators branches */
int add_expressions_branch(llist_t *tokens, tnode_t *head)
{
	lnode_t *node = tokens->tail;
	lnode_t *to_del;
	int position;

	while (node && ((token_t *)(node->data))->type == COMMAND) {
		if (!is_tree_last_expression(node->prev)) {
			head = head->left;
		}
		position = is_last_command(node->prev) ? LEFT : RIGHT;
		if (!push_tnode(node->data, head, position)) {
			return (false);
		}
		to_del = node;
		node = node->prev;
		list_pop(to_del, tokens);
	}
	return (true);
}
