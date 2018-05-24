/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** Functions to put a file in stdin
*/

#include "redirections.h"
#include "binary_tree.h"
#include "42sh.h"
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

static int open_file(char *file_path)
{
	int fd = open(file_path, O_RDONLY);

	if (fd == -1) {
		fprintf(stderr, "%s: %s\n", file_path, strerror(errno));
	}
	return (fd);
}

static int execute_expression(tnode_t *parent, shell_info_t *infos, int *pfd,
		tree_metadata_t *meta)
{
	redirector_func_t *function;

	if (parent->type == COMMAND) {
		if (!redirection_exec_binary(parent, meta, infos, pfd)) {
			return (false);
		}
	}
	function = get_redirector_func(parent->type);
	if (!function || !function(parent, infos, pfd, meta)) {
		return (false);
	}
	return (true);
}

int redirect_file_to_stdin(tnode_t *parent, shell_info_t *infos,
		int *parent_pfd, tree_metadata_t *meta)
{
	int file_fd = open_file(*(parent->right->data.str));
	int pfd[2];

	if (file_fd == -1 || pipe(pfd) == -1 || dup2(pfd[1], file_fd) == -1) {
		return (false);
	}
	if (!execute_expression(parent->left, infos, pfd, meta)) {
		return (false);
	}
	close(file_fd);
	return (true);
}
