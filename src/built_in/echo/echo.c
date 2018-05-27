/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main.c
*/

#include "echo.h"

static const echo_t FLAGS[] = {
	{'\t', 't'},
	{'\a', 'a'},
	{'\b', 'b'},
	{'\f', 'f'},
	{'\v', 'v'},
	{'\e', 'e'},
	{'\r', 'r'},
	{'\n', 'n'},
	{-1, -1},
};

int find_flag(char carac)
{
	int idx = 0;

	while (FLAGS[idx].carac != -1) {
		if (FLAGS[idx].carac == carac) {
			putchar(FLAGS[idx].flag);
			return (0);
		}
		idx++;
	}
	putchar(92);
	putchar(carac);
	return (0);
}

int parsing_element(char *str)
{
	int it = 0;

	while (str[it] != '\0') {
		if (str[it] == 92) {
			find_flag(str[it + 1]);
			it+= 2;
		}
		else {
			putchar(str[it]);
			it++;
		}
	}
	return (0);
}

int check_error(char **tab)
{
	int it = 0;

	while (tab[it]) {
		it++;
	}
	if (it == 1) {
		return (false);
	}
	return (true);
}

int browse_argument(char **tab)
{
	int flags = 0;
	int it = 1;

	if (!check_error(tab)) {
		return (84);
	}
	if (!strcmp(tab[it], "-n")) {
		flags = 1;
		it++;
	}
	while (tab[it]) {
		parsing_element(tab[it]);
		putchar(' ');
		it++;
	}
	if (!flags) {
		putchar('\n');
	}
	return (0);
}
