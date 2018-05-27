/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** Functions to redirect fd into files
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
	int fd = open(file_path, flags | O_CREAT, 0755);

	if (fd == -1) {
		fprintf(stderr, "%s: %s\n", file_path, strerror(errno));
	}
	return (fd);
}

static int execute_expression(tnode_t *parent, shell_info_t *infos,
		tree_metadata_t *meta, redirector_pipes_t pipes)
{
	int io_fd[3];
	redirector_pt_t *function;

	io_fd[IN] = -1;
	io_fd[OUT] = pipes.current[1];
	io_fd[TO_CLOSE] = pipes.current[0];
	if (parent->data.type == COMMAND) {
		if (!redirection_exec_binary(parent, meta, infos, io_fd)) {
			return (false);
		}
	}
	function = get_redirector_func(parent->data.type);
	if (!function || !function(parent, infos, pipes.current, meta)) {
		return (false);
	}
	return (true);
}

static int write_file(int file_fd, int current_pfd[2])
{
	if (dup2(file_fd, current_pfd[0]) == -1) {
		return (false);
	}
	return (true);
}

int redirection_to_file(tnode_t *parent, shell_info_t *infos,
		int *parent_pfd, tree_metadata_t *metadata)
{
	int pfd[2];
	int file_fd = open_file(*(parent->left->data.str), O_WRONLY);
	redirector_pipes_t pipes;

	fprintf(stderr, "Write file\n");
	if (file_fd == -1 || pipe(pfd) == -1) {
		return (false);
	}
	pipes.current = pfd;
	pipes.parent = parent_pfd;
	if (!execute_expression(parent->left, infos, metadata, pipes)) {
		return (false);
	}
	close(pfd[1]);
	write_file(file_fd, pfd);
	close(file_fd);
	close(pfd[0]);
	return (true);
}

int redirection_to_file_append(tnode_t *parent, shell_info_t *infos,
		int *parent_pfd, tree_metadata_t *metadata)
{
	int pfd[2];
	int file_fd = open_file(*(parent->left->data.str), O_WRONLY | O_APPEND);
	redirector_pipes_t pipes;

	fprintf(stderr, "Write file append\n");
	if (file_fd == -1 || pipe(pfd) == -1) {
		return (false);
	}
	pipes.current = pfd;
	pipes.parent = parent_pfd;
	if (!execute_expression(parent->left, infos, metadata, pipes)) {
		return (false);
	}
	close(pfd[1]);
	write_file(file_fd, pfd);
	close(file_fd);
	close(pfd[0]);
	return (true);
}