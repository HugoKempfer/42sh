/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** Functions to redirect fd into files
*/

#include "redirections.h"
#include "binary_tree.h"
#include "42sh.h"
#include "str_manip.h"
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

static int open_file(char *file_path, int flags)
{
	int fd = open(file_path, flags | O_CREAT, 0600);

	if (fd == -1) {
		fprintf(stderr, "%s: %s\n", file_path, strerror(errno));
	}
	return (fd);
}

static int execute_expression(tnode_t *parent, shell_info_t *infos,
		tree_metadata_t *meta, int file_fd)
{
	int io_fd[3];
	int binary_fd[2] = {0, file_fd};
	redirector_pt_t *function;

	io_fd[IN] = -1;
	io_fd[OUT] = file_fd;
	io_fd[TO_CLOSE] = -1;
	if (parent->data.type == COMMAND) {
		if (!redirection_exec_binary(parent, meta, infos, io_fd)) {
			return (false);
		}
		else {
			return (true);
		}
	}
	function = get_redirector_func(parent->data.type);
	if (!function || !function(parent, infos, binary_fd, meta)) {
		return (false);
	}
	return (true);
}

int redirection_to_file(tnode_t *parent, shell_info_t *infos,
		int *parent_pfd, tree_metadata_t *metadata)
{
	int file_fd = open_file(*(parent->right->data.str), O_WRONLY);

	if (file_fd == -1) {
		return (false);
	}
	if (!execute_expression(parent->left, infos, metadata, file_fd)) {
		return (false);
	}
	close(file_fd);
	return (true);
}

int redirection_to_file_append(tnode_t *parent, shell_info_t *infos,
		int *parent_pfd, tree_metadata_t *metadata)
{
	int file_fd = open_file(*(parent->right->data.str), O_WRONLY |
			O_APPEND);

	if (file_fd == -1) {
		return (false);
	}
	if (!execute_expression(parent->left, infos, metadata, file_fd)) {
		return (false);
	}
	close(file_fd);
	return (true);
}
