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
typedef int (redirector_pt_t)(tnode_t *, tnode_t *, int [2], tree_metadata_t *);

struct redirection_func_index_s {
	redirector_pt_t *fptr;
	enum tnode_type type;
};

#endif /* ifndef REDIRECTIONS_H */
