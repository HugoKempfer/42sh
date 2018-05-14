/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** Functions to destroy the lexer's tokens
*/

#include "lexer.h"
#include "list.h"

/* Function which only free the token struct itself */
void destroy_token(void *data)
{
	token_t *token = (token_t *)data;

	free(token);
}
