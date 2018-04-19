/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** Functions to cut a string into sub strings
*/

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>

char **add_line(char **, char *);
char *alloc_n_str(char *, int);

static const char SENTINEL_CHAR[] = {'<', '>', '|', ';', -1};
static const char SEPARATORS[] = {
	'\0',
	' ',
	'\t',
	'\n',
	'<',
	'>',
	'|',
	';',
	-1
};

static bool is_in_arr(char const c, char const *arr)
{
	int it = 0;

	while (arr[it] != -1) {
		if (c == arr[it]) {
			return (true);
		}
		it++;
	}
	return (false);
}

static int get_end_of_str(char *str)
{
	int it = 1;

	while (str && str[it] && str[it] != '"') {
		++it;
		if (str[it] == '"' && str[it - 1] == '\\') {
			++it;
		}
	}
	if (!(str[it])) {
		return (it);
	}
	return (it + 1);
}

static int get_eow(char *str)
{
	int it = 0;

	if (!(str) || !(*(str))) {
		return (-1);
	}
	if (*str == '"') {
		return (get_end_of_str(str));
	}
	else if (is_in_arr(*str, SENTINEL_CHAR)) {
		while (is_in_arr(str[it], SENTINEL_CHAR)) {
			++it;
		}
	}
	else {
		while (!(is_in_arr(str[it], SEPARATORS))) {
			++it;
		}
	}
	return (it);
}

static int get_next_word(char *str, int *cursor)
{
	int it = 0;

	if (!(str) || !(*(str))) {
		return (-1);
	}
	while (is_in_arr(str[it], SEPARATORS)) {
		if (!(str[it])) {
			return (-1);
		}
		if (is_in_arr(str[it], SENTINEL_CHAR)) {
			break;
		}
		++it;
	}
	*cursor += it;
	return (it);
}


char **subdivise_str(char *str)
{
	int it = 0;
	int eow = 0;
	char **tokens = NULL;

	if (!(str)) {
		return (NULL);
	}
	while (get_next_word(str + it, &it) != -1) {
		eow = get_eow(str + it);
		tokens = add_line(tokens, alloc_n_str(str + it, eow));
		if (!(tokens)) {
			return (NULL);
		}
		it += eow;
	}
	return (tokens);
}
