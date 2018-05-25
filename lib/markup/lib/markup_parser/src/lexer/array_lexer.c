/*
** EPITECH PROJECT, 2017
** main.c
** File description:
** Main file of the function
*/

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <markup.h>

static const mtoken_t token_type[] = {
	{"{", BLOCK_ENTRY},
	{"}", BLOCK_END},
	{";", LINE_END},
	{"=", ASSIGN},
	{NULL, DEFAULT}
};

static mtoken_t *create_token(char *str, token_type_t type)
{
	mtoken_t *token = malloc(sizeof(mtoken_t));

	if (!token) {
		return (NULL);
	}
	token->token = str;
	token->type = type;
	return (token);
}

static int get_arr_size(mtoken_t *arr)
{
	int it = 0;

	while (arr && arr[it].token) {
		it++;
	}
	return (it == 0 ? 0 : it);
}

static mtoken_t *add_line(mtoken_t *token_arr, mtoken_t *token)
{
	int it = 0;
	int size = get_arr_size(token_arr);
	mtoken_t *new = NULL;

	new = malloc(sizeof(mtoken_t) * (size + 2));

	if (!new) {
		return (NULL);
	}
	while (token_arr && token_arr[it].token) {
		new[it].token = token_arr[it].token;
		new[it].type = token_arr[it].type;
		it++;
	}
	new[it] = *token;
	new[it + 1].token = NULL;
	free(token);
	free(token_arr);
	return (new != NULL ? new : NULL);
}

static void define_token_type(mtoken_t *token)
{
	int it = 0;
	int it2 = 0;
	token_type_t type = DEFAULT;

	while (token && token[it].token) {
		while (token_type[it2].token && *token_type[it2].token !=
				*token[it].token) {
			it2++;
		}
		type = token_type[it2].type;
		it2 = 0;
		if (type == DEFAULT) {
			type = LABEL;
			if (it > 0 && token[it - 1].type == ASSIGN) {
				type = VALUE;
			}
		}
		token[it].type = type;
		it++;
	}
}

mtoken_t *markup_lexer(char *str)
{
	int it = 0;
	int EOL = 0;
	mtoken_t *tmp = NULL;
	mtoken_t *token_arr = NULL;

	while (get_next_word(&str[it], &it) != -1) {
		if (str[it] == '"') {
			it++;
			EOL = get_next_occur(&str[it], '"');
		} else {
			EOL = get_next_occur(&str[it], ' ');
		}
		tmp = create_token(alloc_nstr(&str[it], EOL), DEFAULT);
		it += EOL;
		token_arr = add_line(token_arr, tmp);
	}
	tmp = create_token(alloc_nstr("",  0), DEFAULT);
	token_arr = add_line(token_arr, tmp);
	define_token_type(token_arr);
	return (token_arr);
}
