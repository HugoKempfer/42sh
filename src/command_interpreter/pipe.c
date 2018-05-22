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

int redirection_pipe(tnode_t *parent_left, tnode_t *parent_right,
		int parent_pfd[2], tree_metadata_t *meta)
{
	int pdf[2];
	redirector_pt_t *function;

	if (pipe(pfd) == -1) {
		return (false);
	}
	if (parent->left->type == COMMAND) {
		//exec command
	}
	function = get_redirector_func(parent_left->left);
	return (true);
}
