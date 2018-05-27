/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** Organize shell parts
*/

#include "42sh.h"
#include "strings.h"
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

static int do_command_parsing(shell_info_t *infos)
{
	char *raw_command = prompt();
	char **cut_command;
	llist_t *tokens;
	cutter_charset_t cutter = {SEPARATORS, SENTINEL_CHAR, SUROUNDINGS};

	if (!prompt) {
		return (false);
	}
	cut_command = subdivise_str(raw_command, cutter);
	if (!cut_command) {
		return (false);
	}
	tokens = tokenize_command(cut_command);
	if (!tokens || !build_trees_from_tokens(tokens, infos)) {
		return (false);
	}
	return (true);
}


int shell_runtime(shell_info_t *infos)
{
	int state = true;

	while (state) {
		if (!do_command_parsing(infos)) {
			return (false);
		}
		process_manager(infos);
	}
	return (true);
}
