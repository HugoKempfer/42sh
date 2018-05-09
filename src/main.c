/*
** EPITECH PROJECT, 2017
** 42sh
** File description:
** main.c
*/

#include "lexer.h"
#include "parser.h"
#include "my.h"
#include "strings.h"
#include "tools.h"
#include "list.h"
#include <stdlib.h>
#include <stdio.h>

static char *SUROUNDINGS[] = {
	"\"\"",
	"()",
	"[]",
	"``",
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

void print(llist_t *tokens)
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
	shell_info_t *info = init_shell_info();

	do {
		str = prompt();
		command = subdivise_str(str, (cutter_charset_t){SEPARATORS, SENTINEL_CHAR, SUROUNDINGS});
		tokens = tokenize_command(command);
		printf("nb tokens [%d]\n", tokens->nb_nodes);
		print(tokens);
		build_trees_from_tokens(tokens, info);
		printf("Nb trees [%d]\n", info->processes->nb_nodes);
	} while (prompt);
	return (0);
}
