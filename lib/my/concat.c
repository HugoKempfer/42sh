/*
** EPITECH PROJECT, 2018
** concat.c
** File description:
** concat.c
*/

#include <stdlib.h>
#include <stdbool.h>
#include <stddef.h>

static size_t get_arr_size(const char **str)
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
	char *new_str = malloc(size);

	if (!size || !new_str) {
		free(new_str);
		return (NULL);
	}
	while (*str) {
		strcpy(new_str, *str);
		new_str += strlen(str);
		++str;
	}
	return (new_str - size);
}
