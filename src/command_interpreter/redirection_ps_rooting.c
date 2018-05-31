/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** Redirection rooting table
*/

#include "built_in_exec.h"
#include "redirections.h"
#include "binary_exec.h"
#include "binary_tree.h"
#include "42sh.h"
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int redirection_exec_builtin(built_in_fptr * func, shell_info_t *infos,
		char **command, int pipes[3]);

int redir_exec_routing(tnode_t *cmd_node, tree_metadata_t *meta,
		shell_info_t *infos, int pipe[3])
{
	int state;
	char **command = cmd_node->data.str;
	built_in_fptr *func = get_builtin_func(*command);

	if (!func) {
		return (redirection_exec_binary(cmd_node, meta, infos, pipe));
	}
	state = redirection_exec_builtin(func, infos, command, pipe);
	meta->return_code = (state) ? 0 : 1;
	return (state);
}
