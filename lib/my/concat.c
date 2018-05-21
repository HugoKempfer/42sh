/*
** EPITECH PROJECT, 2018
** concat.c
** File description:
** concat.c
*/

#include "string.h"
#include <stdlib.h>
#include <stdbool.h>
#include <stddef.h>

void print_dbl_tab(char **buffer);

static size_t get_arr_size(char **str)
{
	size_t size = 0;

	if (!str) {
		return (0);
	}
	while (*str) {
		size += strlen(*str);
		++str;
	}
	return (size);
}

char *str_concat(char **str)
{
	size_t size = get_arr_size(str);
	char *new_str = calloc(size + 1, size + 1);

	if (!size || !new_str) {
		free(new_str);
		return (NULL);
	}
	while (*str) {
		strcat(new_str, *str);
		++str;
	}
	return (new_str);
}
