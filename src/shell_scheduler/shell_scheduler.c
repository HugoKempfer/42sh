/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** Organize shell parts
*/

#include "42sh.h"
#include "str_manip.h"
#include "metadata.h"
#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>
#include <unistd.h>

int process_tree(shell_info_t *infos, tree_metadata_t *meta);
int process_manager(shell_info_t *infos);
int build_trees_from_tokens(llist_t *tokens, shell_info_t *shell_info);
int check_syntax_command(llist_t *tokens);
char *prompt(void);

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

int check_syntax_command(llist_t *tokens);

static int do_syntax_build_tree(shell_info_t *infos, llist_t *tokens)
{
	if (!tokens) {
		return (MISTAKE);
	}
	if (!check_syntax_command(tokens)) {
		return (SYNTAX);
	}
	if (!build_trees_from_tokens(tokens, infos)) {
		return (MISTAKE);
	}
	return (EXEC);
}

int stock_history(shell_info_t *infos, char *command);

static int do_command_parsing(shell_info_t *infos)
{
	char *raw_command = prompt();
	char **cut_command;
	llist_t *tokens;
	cutter_charset_t cutter = {SEPARATORS, SENTINEL_CHAR, SUROUNDINGS};

	if (!prompt) {
		return (MISTAKE);
	} else if (raw_command && !strcmp(raw_command, "\n")) {
		return (SYNTAX);
	}
	cut_command = subdivise_str(raw_command, cutter);
	if (!cut_command) {
		return (MISTAKE);
	}
	stock_history(infos, raw_command);
	tokens = tokenize_command(cut_command);
	return (do_syntax_build_tree(infos, tokens));
}

int shell_runtime(shell_info_t *infos)
{
	int state = true;
	int step = 0;

	while (state) {
		step = do_command_parsing(infos);
		if (step == EXEC) {
			process_manager(infos);
		}
		else if (step == MISTAKE) {
			return (false);
		}
	}
	return (true);
}
