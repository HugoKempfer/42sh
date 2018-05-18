/*
** EPITECH PROJECT, 2018
** file_ordering_utils.c
** File description:
** utilities
*/

#include "functions.h"
#include "my.h"

void print_the_grid_known_limit(char **filename, int limit)
{
	int idx = 0;

	while (limit != 0) {
		my_putstr(filename[idx]);
		my_putchar('\n');
		++idx;
		--limit;
	}
}

int is_sorted(char **filename, int limit)
{
	int idx = 0;

	while (limit != 0) {
		if (filename[idx][0] > filename[idx + 1][0]) {
			return (0);
		}
		idx++;
		limit--;
	}
	return (1);
}