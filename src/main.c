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
#include "list.h"
#include "lexer.h"

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
	'&',
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
	'&',
	-1
};

char *prompt(void);

static void print(llist_t *tokens)
{
	lnode_t *node = tokens->head;

	while (node) {
		printf("[%d]\n", ((token_t *)(node->data))->type);
		node = node->next;
	}
}

int main(int unused ac, char unused **av)
{
	char *str = NULL;
	char **command = NULL;
	llist_t *tokens = NULL;

	do {
		str = prompt();
		command = subdivise_str(str, (cutter_charset_t){SEPARATORS, SENTINEL_CHAR, SUROUNDINGS});
		tokens = tokenize_command(command);
		printf("nb tokens [%d]\n", tokens->nb_nodes);
		print(tokens);
	} while (prompt);
	return (0);
}
