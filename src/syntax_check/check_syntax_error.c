/*
** EPITECH PROJECT, 2018
** check_syntax_error.c
** File description:
** check_syntax_error.c
*/

#include "list.h"
#include "lexer.h"
#include "tools.h"
#include "strings.h"
#include <stdbool.h>

int check_type(int prev_type, int current_type)
{
	if (prev_type == COMMAND && (current_type < OR || current_type > INF)) {
		return (false);
	}
	if ((prev_type >= OR && prev_type <= INF) && current_type != COMMAND) {
		return (false);
	}
	return (true);
}

int check_syntax_command(llist_t *tokens)
{
	lnode_t *node = tokens->head;
	int prev_type = ((token_t *)(node->data))->type;

	node = node->next;
	while (node) {
		if (!check_type(prev_type, ((token_t *)(node->data))->type)) {
			return (false);
		}
		prev_type = ((token_t *)(node->data))->type;
		node = node->next;
	}
	return (true);
}
