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
/*int print_error_command(int prev_type, int current_type)
{
	if (prev_type == current_type && prev_type == PIPE) {
		fprintf(stderr, "Invalid null command.");
	}
	return (true);
}

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
}*/

int compare_type(int current_type, int second_type, llist_t *tokens)
{
	if (current_type == second_type && current_type == COMMAND) {
		return (false);

	}
	if (tokens->nb_nodes == 2 && )

}

int check_syntax_command(llist_t *tokens)
{
	lnode_t *node = tokens->head;
	int check = 0;
	int current_type = ((token_t *)(node->data))->type;
	int second_type = 0;

	while (node->next) {
		second_type = ((token_t *)(node->next->data))->type;
		check = compare_type(current_type, second_type, tokens);
		if(!check) {
			return (false);
		}
		node = node->next;
	}
	return (true);
}
