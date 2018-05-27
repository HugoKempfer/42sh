/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** Annex
*/

#include "binary_tree.h"
#include "list.h"
#include "lexer.h"
#include "parser.h"
#include "42sh.h"
#include "tools.h"

int push_tnode(token_t *token, tnode_t *head, int position)
{
	tnode_data_t data = {token->type, token->value};

	if (!(create_and_link(head, data, position))) {
		return (false);
	}
	return (true);
}
