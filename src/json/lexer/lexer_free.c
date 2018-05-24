/*
** EPITECH PROJECT, 2017
** lexer_free.c
** File description:
** Function to destroy the token array
*/

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>
#include <markup.h>

int destroy_token_arr(mtoken_t *arr)
{
	int it = 0;

	while (arr && arr[it].token) {
		free(arr[it].token);
		it++;
	}
	free(arr);
	return (true);
}
