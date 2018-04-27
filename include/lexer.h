/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** Main header of the lexer
*/

#ifndef LEXER_H
#define LEXER_H

#include "tools.h"

typedef struct token_s token_t;
typedef struct token_type_list_s token_type_list_t;

enum token_type {
	OR,
	D_SUP,
	D_INF,
	AND,
	PIPE,
	SUP,
	INF,
	SEMI_COLON,
	COMMAND
};

/* Struct of the token itself */
struct token_s {
	enum token_type type;
	char **value;
};

/* Structure of the branch table */
struct token_type_list_s {
	char *str;
	enum token_type type;
};

llist_t *tokenize_command(char **command);
void destroy_token(void *data);

#endif /* ifndef LEXER_H */
