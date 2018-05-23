/*
** EPITECH PROJECT, 2018
** 42sh** File description:
** Manage the sub_processes fd's connexions
*/

#include "redirection.h"
#include "binary_tree.h"
#include "42sh.h"
#include "tools.h"
#include <unistd.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

static const redirection_func_index_t REDIRECTORS[] = {
	{&redirector_pipe, PIPE}
};

redirector_pt_t *get_redirector_func(enum tnode_type type)
{
	size_t it = 0;

	while (it < (size_t)ARRAY_SIZE(REDIRECTORS)) {
		if (type == REDIRECTORS.type) {
			return (REDIRECTORS.fptr);
		}
		++it;
	}
	return (NULL);
}

int process_tree(shell_infos_t *infos, tree_metadata_t *meta)
{
	int pfd[2];
	redirector_pt_t *function;
	tnode_t *head = metadata->head;

	if (pipe(pfd) == -1 || dup2(pfd[0], 1) == -1) {
		return (false);
	}
	close(pfd[1]);
	function = get_redirector_func(head->left->type);
	if (!function || !function(head->left->left, head->left->right, pfd)) {
		close(pfd[1]);
		close(pfd[0]);
		if (head->left->type == COMMAND) {
			return (exec_binary(head->left.data->str, infos, meta));
		}
		return (false);
	}
	close(pfd[1]);
	close(pfd[0]);
	return (true);
}

