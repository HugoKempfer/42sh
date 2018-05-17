/*
** EPITECH PROJECT, 2018
** concat.c
** File description:
** concat.c
*/

#include <stdlib.h>
#include <stdbool.h>

static int size_concat(char **str)
{
	int it = 0;
	int it2 = 0;
	int size = 0;

	while (str[it]) {
		while (str[it][it2]) {
			it2++;
			size++;
		}
		it2 = 0;
		it++;
	}
	return (size);
}

char *str_concat(char **str)
{
	int size = size_concat(str);
	int it = 0;
	int it2 = 0;
	int idx_str = 0;
	char *new_string = malloc(sizeof(char) * (size + 1));

	if (!new_string) {
		return (false);
	}
	while (str[it]) {
		while (str[it][it2]) {
			new_string[idx_str] = str[it][it2];
			idx_str++;
			it2++;
		}
		it2 = 0;
		it++;
	}
	new_string[idx_str] = '\0';
	return (new_string);
}
