/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** Manage binary fd redirections
*/

#ifndef REDIRECTIONS_H
#define REDIRECTIONS_H

#include "binary_tree.h"
#include "42sh.h"
#include "metadata.h"

typedef struct redirector_pipes_s redirector_pipes_t;
typedef struct redirection_func_index_s redirection_func_index_t;
typedef int (redirector_pt_t)(tnode_t *, shell_info_t *, int *parent_pipes,
		tree_metadata_t *);

struct redirection_func_index_s {
	redirector_pt_t *fptr;
	enum tnode_type type;
};

struct redirector_pipes_s {
	int *parent;
	int *current;
};

int redirection_exec_binary(tnode_t *cmd_node, tree_metadata_t *meta,
		shell_info_t *infos, redirector_pipes_t pipes);
redirector_pt_t *get_redirector_func(enum tnode_type type);

#endif /* ifndef REDIRECTIONS_H */
