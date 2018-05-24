/*
** EPITECH PROJECT, 2017
** strings.c
** File description:
** Function to manage the strings
*/

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

char *alloc_str(char *str, int len)
{
	int it = 0;
	char *string  = NULL;

	string = malloc(sizeof(char) * (len + 1));
	if (!(string) || len == 0) {
		free(string);
		return (NULL);
	}
	while (it < len) {
		string[it] = str[it];
		it++;
	}
	string[it] = '\0';
	return (string);
}

int get_next_word(char *str, int *cursor)
{
	int it = 0;

	if (!(str) || !(*(str))) {
		return (-1);
	}
	while (str[it] == ' ' || str[it] == '\t' || str[it] == '\n') {
		++(it);
	}
	*cursor = *cursor + it;
	return (it);
}

int get_next_occur(char *str, char c)
{
	int it = 0;

	if (!(str)) {
		return (-1);
	}
	while (str[it] && (str[it] != c) && (str[it] != '\n')) {
		++(it);
	}
	return (it);
}
