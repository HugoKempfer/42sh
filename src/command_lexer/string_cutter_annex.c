/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** Annex functions of the string cutter
*/

#include "tools.h"
#include "str_manip.h"

char *remove_surroundings(char *str)
{
	char *new = NULL;

	new = alloc_n_str(str + 1, strlen(str + 1) - 1);
	free(str);
	return (new);
}

int get_end_of_str(const char *str, const char *surroundings)
{
	int it = 1;

	while (str && str[it]) {
		if (str[it] == surroundings[1]) {
			break;
		}
		++it;
	}
	return (it + 1);
}
