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

static int process_second_expression(tnode_t *parent, shell_info_t *infos,
		tree_metadata_t *meta, redirector_pipes_t pipes)
{
	redirector_pt_t *function;
	int io_fd[3];

	io_fd[IN] = pipes.current[0];
	io_fd[OUT] = pipes.parent[1];
	io_fd[TO_CLOSE] = pipes.current[1];
	if (!redirection_exec_binary(parent, meta, infos, io_fd)) {
		return (false);
	}
	return (true);
}

static int process_first_expression(tnode_t *parent, shell_info_t *infos,
		tree_metadata_t *meta, redirector_pipes_t pipes)
{
	printf("PIPE FUNCTION [%d] [%d]\n", pipes.parent[0], pipes.parent[1]);
	int io_fd[3];
	redirector_pt_t *function;

	io_fd[IN] = -1;
	io_fd[OUT] = pipes.current[1];
	io_fd[TO_CLOSE] = pipes.current[0];
	if (parent && parent->data.type != COMMAND) {
		function = get_redirector_func(parent->data.type);
		if (!function(parent, infos, pipes.current, meta)) {
			return (false);
		}
		return (true);
	}
	else if (!redirection_exec_binary(parent, meta, infos, io_fd)) {
		return (false);
	}
	return (true);
}

int redirection_pipe(tnode_t *parent, shell_info_t *infos,
		int *parent_pfd, tree_metadata_t *meta)
{
	int pfd[2];
	int status;
	redirector_pt_t *function;
	redirector_pipes_t pipes;

	if (pipe(pfd) == -1) {
		return (false);
	}
	pipes.parent = parent_pfd;
	pipes.current = pfd;
	if (!process_first_expression(parent->left, infos, meta, pipes)) {
		return (false);
	}
	status = process_second_expression(parent->right, infos, meta, pipes);
	close(pipes.current[0]);
	close(pipes.current[1]);
	return (status);
}
