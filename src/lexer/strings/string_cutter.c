/*
** EPITECH PROJECT, 2018
** Lemin
** File description:
** Functions to cut a string into sub strings
*/

#include <stddef.h>
#include <stdbool.h>
#include "lexer_explicit.h"
#include "strings.h"
#include "tools.h"

static const char SENTINEL_CHAR[] = {'-', '\t', -1};
static const char SEPARATORS[] = {'\0', ' ', '\t', '\n', '-', -1};

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

static int get_eow(char *str, cutter_charset_t *charset)
{
	int it = 0;

	if (!(str) || !(*(str))) {
		return (-1);
	}
	if (is_in_arr(*str, SENTINEL_CHAR)) {
		while (is_in_arr(str[it], charset->kept_separators)) {
			it++;
		}
	}
	else {
		while (!(is_in_arr(str[it], charset->separators))) {
			it++;
		}
	}
	return (it);
}

static int get_next_word(char *str, int *cursor, cutter_charset_t *charset)
{
	int it = 0;

	if (!(str) || !(*(str))) {
		return (-1);
	}
	while (is_in_arr(str[it], charset->separators)) {
		if (!(str[it])) {
			return (-1);
		}
		if (is_in_arr(str[it], charset->kept_separators)) {
			break;
		}
		it++;
	}
	*cursor += it;
	return (it);
}

char **subdivise_str(char *str, cutter_charset_t *charset)
{
	int it = 0;
	int eow = 0;
	char **tokens = NULL;

	if (!(str)) {
		return (NULL);
	}
	while (get_next_word(str + it, &it, charset) != -1) {
		eow = get_eow(str + it, charset);
		tokens = add_line(tokens, alloc_n_str(str + it, eow));
		if (!(tokens)) {
			return (NULL);
		}
		it += eow;
	}
	return (tokens);
}
