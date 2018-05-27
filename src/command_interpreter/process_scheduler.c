/*
** EPITECH PROJECT, 2018
** 42sh** File description:
** Manage the sub_processes fd's connexions
*/

#include "redirections.h"
#include "binary_tree.h"
#include "binary_exec.h"
#include "42sh.h"
#include "tools.h"
#include <unistd.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

static const redirection_func_index_t REDIRECTORS[] = {
	{&redirection_pipe, PIPE}
};

redirector_pt_t *get_redirector_func(enum tnode_type type)
{
	size_t it = 0;

	while (it < (size_t)ARRAY_SIZE(REDIRECTORS)) {
		if (type == REDIRECTORS->type) {
			return (REDIRECTORS->fptr);
		}
		++it;
	}
	return (NULL);
}

int process_tree(shell_info_t *infos, tree_metadata_t *meta)
{
	int pfd[2];
	redirector_pt_t *function;
	tnode_t *head = meta->head;

	//if (pipe(pfd) == -1) {
	//	return (false);
	//}
	pfd[1] = 1;
	pfd[0] = 0;
	printf("PIPE ROOT [%d] [%d]\n", pfd[0], pfd[1]);
	function = get_redirector_func(head->left->data.type);
	if (!function || !function(head->left, infos, pfd, meta)) {
		if (head->left->data.type == COMMAND) {
			return (exec_binary(head->left->data.str, infos, meta));
		}
		return (false);
	}
//	dup2(1, pfd[0]);
	return (true);
}
