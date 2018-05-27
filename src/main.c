/*
** EPITECH PROJECT, 2017
** 42sh
** File description:
** main.c
*/

#include "lexer.h"
#include "42sh.h"
#include "parser.h"
#include "my.h"
#include "strings.h"
#include "tools.h"
#include "metadata.h"
#include "post_processing.h"
#include "list.h"
#include <stdlib.h>
#include <stdio.h>

const static char *SUROUNDINGS[] = {
	"\"\"",
	"()",
	"``",
	"\'\'",
	NULL
};

const static char SENTINEL_CHAR[] = {
	'<',
	'>',
	'|',
	';',
	'&',
	-1
};

const static char SEPARATORS[] = {
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
		if (((token_t *)(node->data))->type == COMMAND) {
			print_dbl_tab(((token_t *)(node->data))->value);
		}
		printf("\n");
		node = node->next;
	}
}

void print_tree(tnode_t *head)
{
	while (head) {
		head->left ? printf("Left [%d]\n", head->left->data.type) : 0;
		head->left ? print_dbl_tab(head->left->data.str) : 0;
		head->right ? printf("Right [%d]\n", head->right->data.type) : 0;
		head->right ? print_dbl_tab(head->right->data.str) : 0;
		head = head->left;
	}
}

int exec_binary(char **command, shell_info_t *infos, tree_metadata_t *meta);

int main(int unused ac, char unused **av, char **env)
{
	shell_info_t *info = init_shell_info(env);
	char *str = NULL;
	char **command = NULL;
	llist_t *tokens = NULL;
	tree_metadata_t metadata = {'\0'};

//	exec_binary(av + 1, info, &metadata);
	const cutter_charset_t cutter = {SEPARATORS, SENTINEL_CHAR, SUROUNDINGS};
	do {
		str = prompt();
		command = subdivise_str(str, cutter);
		tokens = tokenize_command(command);
//		print(tokens);
		build_trees_from_tokens(tokens, info);
//		print_tree(info);
	} while (prompt);
	return (0);
}
