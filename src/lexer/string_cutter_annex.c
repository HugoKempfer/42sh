/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** Annex functions of the string cutter
*/

#include "tools.h"
#include "strings.h"

char *remove_surroundings(char *str)
{
	char *new = NULL;

	new = alloc_n_str(str + 1, strlen(str + 1) - 1);
	free(str);
	return (new);
}

int get_end_of_str(const char *str, char *surroundings)
{
	int it = 1;
	int count = 1;

	while (str && str[it] && count) {
		++it;
		if (str[it] == surroundings[1] && str[it - 1] == '\\') {
			++it;
			continue;
		}
		if (str[it] == *surroundings) {
			++count;
		} else if (str[it] == surroundings[1]) {
			--count;
		}
	}
	if (!(str[it])) {
		return (it);
	}
	return (it + 1);
}
