/*
** EPITECH PROJECT, 2017
** strings.c
** File description:
** Function to manage the strings
*/

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

int my_strlen(char *str)
{
	int it = 0;

	if (!str) {
		return (0);
	}
	while (str && str[it] != '\0') {
		it++;
	}
	return (it);
}

char *alloc_nstr(char *str, int len)
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

//Function which returns the position of the next occurence of the given char
int get_next_occur(char *str, char c)
{
	int it = 0;

	if (!(str)) {
		return (-1);
	}
	while (str[it] && (str[it] != c) && (str[it] != '\n')) {
		it++;
	}
	return (it);
}

int	my_strcmp(const char *s1, const char *s2)
{
	int it = 0;

	if (!s1 || !s2) {
		return (0);
	}
	while (s1[it] == s2[it]) {
		if (s1[it] == '\0' && s2[it] == '\0') {
			return (0);
		}
		it++;
	}
	return (s1[it] - s2[it]);
}
