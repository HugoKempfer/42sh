/*
** EPITECH PROJECT, 2018
** 42sh** File description:
** Manage the sub_processes fd's connexions
*/

#include "built_in_exec.h"
#include "redirections.h"
#include "post_processing.h"
#include "binary_tree.h"
#include "binary_exec.h"
#include "42sh.h"
#include "tools.h"
#include <unistd.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int process_manager(shell_info_t *infos);
int build_trees_from_tokens(llist_t *tokens, shell_info_t *shell_info);

static const redirection_func_index_t REDIRECTORS[] = {
	{&redirection_pipe, PIPE},
	{&redirection_to_file_append, D_SUP},
	{&redirection_to_file, SUP},
	{&redirection_buffer_to_stdin, D_INF},
	{&redirection_file_to_bin, INF}
};

redirector_pt_t *get_redirector_func(enum tnode_type type)
{
	size_t it = 0;

	while (it < (size_t)ARRAY_SIZE(REDIRECTORS)) {
		if (type == REDIRECTORS[it].type) {
			return (REDIRECTORS[it].fptr);
		}
		++it;
	}
	return (NULL);
}

int execute_command(shell_info_t *infos, tree_metadata_t *meta)
{
	char **command = meta->head->left->data.str;
	built_in_fptr *fptr = get_builtin_func(command[0]);

	if (fptr && !fptr(infos, command)) {
		return (false);
	} else if (!fptr && !exec_binary(command, infos, meta)) {
		return (false);
	}
	return (true);
}

int process_tree(shell_info_t *infos, tree_metadata_t *meta)
{
	int pfd[2]= {-1, -1};
	redirector_pt_t *function;
	tnode_t *head = meta->head;
	int builtin = 0;

//	tree_post_processing(infos, meta, head);
	function = get_redirector_func(head->left->data.type);
	if (!function || !function(head->left, infos, pfd, meta)) {
		if (head->left->data.type == COMMAND) {
			return (execute_command(infos, meta));
		}
		return (false);
	}
	return (true);
}
