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
	PIPE,
	SUP,
	INF,
	D_SUP,
	D_INF,
	SEMI_COLON,
	PARENTHESES,
	BACK_TICKS,
	AND,
	OR,
	COMMAND
};

struct token_s {
	enum token_type type;
	char **value;
};
struct token_type_list_s {
	char *str;
	enum token_type type;
};

llist_t *tokenize_command(char **command);

#endif /* ifndef LEXER_H */
