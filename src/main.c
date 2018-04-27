/*
** EPITECH PROJECT, 2017
** 42sh
** File description:
** main.c
*/

#include <stdlib.h>
#include <stdio.h>
#include "my.h"
#include "functions.h"
#include "tools.h"
#include "strings.h"

static char *SUROUNDINGS[] = {
	"\"\"",
	"()",
	"[]",
	NULL
};

static char SENTINEL_CHAR[] = {
	'<',
	'>',
	'|',
	';',
	-1
};
static char SEPARATORS[] = {
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

char *prompt(void);

static void print(char **str)
{
	int it = 0;

	while (str[it]) {
		printf("[%s]\n", str[it]);
		++it;
	}
}

int main(int unused ac, char unused **av)
{
	char *str = NULL;
	char **command = NULL;

	do {
		str = prompt();
		command = subdivise_str(str, (cutter_charset_t){SEPARATORS, SENTINEL_CHAR, SUROUNDINGS});
		print(command);
	} while (prompt);
	return (0);
}
