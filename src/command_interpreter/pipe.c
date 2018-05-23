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
		tree_metadata_t *meta, redirectors_pipes_t pipes)
{
	redirector_pt_t *function;

	if (!redirection_exec_binary(parent_right, meta, infos, pipes)) {
		return (false);
	}
	close(pfd[0]);
	close(pfd[1]);
	return (true);
}

int redirection_pipe(tnode_t *parent, shell_info_t *infos,
		int parent_pfd[2], tree_metadata_t *meta)
{
	int pdf[2];
	redirector_pt_t *function;
	reidrectors_pipes_t pipes;

	if (pipe(pfd) == -1) {
		return (false);
	}
	pipes.parent_pfd = parent_pfd;
	pipes.pfd = pfd;
	if (parent->left->type == COMMAND) {
		redirection_exec_binary(tnode_t *node, meta, )
	} else {
		function = get_redirector_func(parent_left->left);
		if (!function(parent, infos, pfd, meta)) {
			close(pfd[0]);
			close(pfd[1]);
			return (false);
		}
	}
	return (process_second_expression(parent->right, infos, meta, pipes));
}
