/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** Functions to create a buffer and send it to stdin
*/

#include "redirections.h"
#include "tools.h"
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

static char *custom_prompt(void)
{
	char *line = NULL;
	size_t len;

	fputs("? ", stdout);
	if (getline(&line, &len, stdin) == -1) {
		free(line);
		return (NULL);
	}
	return (line);
}

static void fill_pipe_buffer(int *pfd, char *end_str)
{
	char *line = NULL;

	do {
		line = NULL;
		line = custom_prompt();
		if (!strncmp(line, end_str, strlen(end_str))) {
			break;
		}
		if (line) {
			write(pfd[1], line, strlen(line));
		}
	} while (line);
}

int redirection_buffer_to_stdin(tnode_t *parent, shell_info_t *infos,
		int *parent_pfd, tree_metadata_t *metadata)
{
	int pfd[2];
	int io_fd[3];

	if (pipe(pfd) == -1) {
		return (false);
	}
	fill_pipe_buffer(pfd, *(parent->right->data.str));
	close(pfd[1]);
	io_fd[IN] = pfd[0];
	io_fd[OUT] = parent_pfd[1];
	io_fd[TO_CLOSE] = pfd[1];
	if (!execute_expression(parent->left, infos, metadata, io_fd)) {
		return (false);
	}
	close(pfd[0]);
	return (true);
}
