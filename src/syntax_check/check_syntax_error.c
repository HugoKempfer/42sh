/*
** EPITECH PROJECT, 2018
** check_syntax_error.c
** File description:
** check_syntax_error.c
*/

#include "list.h"
#include "lexer.h"
#include "tools.h"
#include "str_manip.h"
#include <stdbool.h>

int print_error_redirection(int prev, int current)
{
	if (prev >= SEMI_COLON && prev <= INF && prev != PIPE) {
		fprintf(stderr, "Missing name for redirect.\n");
	}
	else if (current >= SEMI_COLON && current <= INF && current != PIPE) {
		fprintf(stderr, "Missing name for redirect.\n");
	} else {
		fprintf(stderr, "Invalid null command.\n");
	}
	return (true);
}

int print_syntax_error(int type)
{
	if (type == OR || type == AND || type == PIPE) {
		fprintf(stderr, "Invalid null command.\n");
	}
	else if (type >= SEMI_COLON && type <= INF) {
		fprintf(stderr, "Missing name for redirect.\n");
	}
	return (true);
}

int check_type(int prev_type, int current_type)
{
	if (prev_type == COMMAND && (current_type < OR || current_type > INF)) {
		return (false);
	}
	if ((prev_type >= OR && prev_type <= INF) && current_type != COMMAND) {
		print_error_redirection(prev_type, current_type);
		return (false);
	}
	return (true);
}

int check_syntax_command(llist_t *tokens)
{
	lnode_t *node = tokens->head;
	int prev_type = ((token_t *)(node->data))->type;

	if (prev_type != COMMAND) {
		return (false);
	}
	node = node->next;
	while (node) {
		if (!check_type(prev_type, ((token_t *)(node->data))->type)) {
			return (false);
		}
		if (((token_t *)(node->data))->type != COMMAND && !node->next) {
			print_syntax_error(((token_t *)(node->data))->type);
			return (false);
		}
		prev_type = ((token_t *)(node->data))->type;
		node = node->next;
	}
	return (true);
}
