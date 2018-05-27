/*
** EPITECH PROJECT, 2017
** 42sh
** File description:
** main.c
*/

#include "redirections.h"
#include "lexer.h"
#include "42sh.h"
#include "parser.h"
#include "my.h"
#include "strings.h"
#include "tools.h"
#include "metadata.h"
#include "list.h"
#include <stdlib.h>
#include <stdio.h>

const static char *SUROUNDINGS[] = {
	"\"\"",
	"()",
	"[]",
	"``",
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

static void print_da(char **arr)
{
	while (arr && *arr) {
		printf("[%s]\n", *arr);
		++(arr);
	}
}

void print(llist_t *tokens)
{
	lnode_t *node = tokens->head;

	while (node) {
		printf("[%d]\n", ((token_t *)(node->data))->type);
		node = node->next;
	}
}

static void print_tree(shell_info_t *infos)
{
	lnode_t *node = infos->processes->head;
	tree_metadata_t *metadata;
	tnode_t *head;

	while (node) {
		metadata = node->data;
		head = metadata->head->left;
		printf("Printing tree ----------------------\n");
		while (head) {
			head->left ? printf("Left [%d]", head->left->data.type) : 0;
			head->left ? print_da(head->left->data.str) : 0;
			head->right ? printf("Right [%d]", head->right->data.type) : 0;
			head->right ? print_da(head->right->data.str) : 0;
			printf("PARENT [%d]\n", head->data.type);
			if (head->data.str) {
				print_da(head->data.str);
			}
			head = head->left;
		}
		node = node->next;
	}
}

int exec_binary(char **command, shell_info_t *infos, tree_metadata_t *meta);
redirector_pt_t *get_redirector_func(enum tnode_type type);

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
		print_dbl_tab(command);
		tokens = tokenize_command(command);
		//print(tokens);
		build_trees_from_tokens(tokens, info);
		//print_tree(info);
		process_tree(info, info->processes->head->data);
	} while (prompt);
	return (0);
}
