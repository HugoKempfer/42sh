/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** Functions to put a file in stdin
*/


#include "redirections.h"
#include "binary_tree.h"
#include "42sh.h"
#include "string.h"
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
	int fd = open(file_path, flags);

	if (fd == -1) {
		fprintf(stderr, "%s: %s\n", file_path, strerror(errno));
	}
	return (fd);
}

static int execute_expression(tnode_t *parent, shell_info_t *infos,
		tree_metadata_t *meta, int io_fd[3])
{
	if (parent->data.type == COMMAND) {
		if (!redirection_exec_binary(parent, meta, infos, io_fd)) {
			return (false);
		}
	}
	return (true);
}

int redirection_file_to_bin(tnode_t *parent, shell_info_t *infos,
		int *parent_pfd, tree_metadata_t *metadata)
{
	int file_fd = open_file(*(parent->right->data.str), O_RDONLY);
	int io_fd[3] = {file_fd, parent_pfd[1], parent_pfd[0]};

	if (file_fd == -1) {
		return (false);
	}
	if (!execute_expression(parent->left, infos, metadata, io_fd)) {
		return (false);
	}
	close(file_fd);
	return (true);
}
