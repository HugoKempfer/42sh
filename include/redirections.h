/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** Manage binary fd redirections
*/

#ifndef REDIRECTIONS_H
#define REDIRECTIONS_H

#include "binary_tree.h"

typedef struct redirection_func_index_s redirection_func_index_t;
typedef int (redirector_pt_t)(tnode_t *, shell_info_t *, int [2],
		tree_metadata_t *);
typedef struct redirector_pipes_s redirectors_pipes_t;

struct redirection_func_index_s {
	redirector_pt_t *fptr;
	enum tnode_type type;
};

struct redirectors_pipes_s {
	int parent_pfd[2];
	int pfd[2];
};

int redirection_exec_binary(tnode_t *cmd_node, tree_metadata_t *meta,
		shell_info_t *infos);

#endif /* ifndef REDIRECTIONS_H */
