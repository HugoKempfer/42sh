/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** Main header of the lexer
*/

#ifndef LEXER_H
#define LEXER_H

#include "tools.h"

typedef struct token_s token_t

enum token_type {
	PIPE,
	SUP,
	INF,
	D_SUP,
	D_INF,
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
#endif /* ifndef LEXER_H */
