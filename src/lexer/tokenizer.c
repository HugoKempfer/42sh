/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** Functions to tokenize the cut command
*/

#include "list.h"
#include "lexer.h"
#include "tools.h"
#include "strings.h"

static const token_type_list_t TYPES[] = {
	{"|", PIPE},
	{">", SUP},
	{"<", INF},
	{">>", D_SUP},
	{"<<", D_INF},
	{";", SEMI_COLON},
	{"(", PARENTHESES},
	{"`", BACK_TICKS},
	{"&&", AND},
	{"||", OR},
	{"", COMMAND}
};

static enum token_type get_token_type(char *str)
{
	int it = 0;

	while (it < (int)ARRAY_SIZE(TYPES)) {
		if (!(strncmp(str, TYPES[it].str, strlen(TYPES[it].str)))) {
			return (TYPES[it].type);
		}
		++it;
	}
	return (COMMAND);
}

static token_t *create_token(char **value, enum token_type type)
{
	token_t *token = malloc(sizeof(*token));

	if (!(token)) {
		return (NULL);
	}
	token->value = value;
	token->type = type;
	return (token);
}

static int process(llist_t *tokens, enum token_type type, char **value)
{
	token_t *token = create_token(NULL, type);

	if (!(token)) {
		return (false);
	}
	if (type == COMMAND && value) {
		printf("It's a command and TRUE\n");
		token->value = value;
		if (!(list_push_tail(token, tokens))) {
			free(token);
			return (false);
		}
	}
	else if (type == COMMAND && !(value)) {
		printf("Empty command\n");
		free(token);
		return (true);
	}
	return (list_push_tail(token, tokens));
}

static int check_process(llist_t *tokens, enum token_type type, char **value)
{
	printf("CHECK PROCESS\n");
	if (!(process(tokens, COMMAND, value))) {
		return (false);
	}
	if (!(process(tokens, type, NULL))) {
		return (false);
	}
	return (true);
}

llist_t *tokenize_command(char **command)
{
	llist_t *tokens = list_init(NULL);
	enum token_type type;
	char **value = NULL;

	while (command && *command) {
		type = get_token_type(*(command));
		if (type == COMMAND) {
			printf("COMMAND\n");
			value = add_line(value, *(command));
			++command;
			continue;
		}
		else if (check_process(tokens, type, value)) {
			list_destroy(tokens);
			return (NULL);
		}
		printf("SEPARATOR\n");
		value = NULL;
		++command;
	}
	return ((process(tokens, COMMAND, value) ? tokens : NULL));
}
