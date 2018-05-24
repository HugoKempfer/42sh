/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** Handle pipe redirections
*/

#include "redirections.h"
#include "binary_tree.h"
#include "42sh.h"
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static int process_second_expression(tnode_t *parent_right, shell_info_t *infos,
		tree_metadata_t *meta, redirector_pipes_t pipes)
{
	redirector_pt_t *function;

	if (!redirection_exec_binary(parent_right, meta, infos, pipes)) {
		return (false);
	}
	close(pipes.current[0]);
	close(pipes.current[1]);
	return (true);
}

int redirection_pipe(tnode_t *parent, shell_info_t *infos,
		int *parent_pfd, tree_metadata_t *meta)
{
	int pfd[2];
	redirector_pt_t *function;
	redirector_pipes_t pipes;

	if (pipe(pfd) == -1) {
		return (false);
	}
	pipes.parent_pfd = parent_pfd;
	pipes.current = pfd;
	if (parent->left->data.type == COMMAND) {
		if (!redirection_exec_binary(parent->left, meta, infos, pipes)) {
			return (false);
		}
	} else {
		function = get_redirector_func(parent->left->data.type);
		if (!function(parent, infos, pfd, meta)) {
			return (false);
		}
	}
	return (process_second_expression(parent->right, infos, meta, pipes));
}
