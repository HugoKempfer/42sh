/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** post processing header
*/

#ifndef POST_PROCESSING_H
#define POST_PROCESSING_H

#include "42sh.h"
#include "list.h"

typedef struct post_processing_s post_processing_t;

struct post_processing_s {
	int (*command_analyser)(shell_info_t *, char *);
	llist_t *(*process_values)(shell_info_t *, tree_metadata_t *, char *);
};

int is_alias(shell_info_t *infos, char *lexem);
int is_var(shell_info_t *infos, char *lexem);
int is_globings(shell_info_t *infos, char *lexem);
int is_double_coat(shell_info_t *infos, char *lexem);
int is_simple_coat(shell_info_t *infos, char *lexem);
llist_t *process_globings(shell_info_t *infos,
			tree_metadata_t *meta, char *str);
llist_t *process_coats(shell_info_t *infos,
			tree_metadata_t *metadata, char *lexem);
int tree_post_processing(shell_info_t *infos, tree_metadata_t *metadata,
			tnode_t *tree_node);
llist_t *process_alias(shell_info_t *infos, char *str);
llist_t *process_var(shell_info_t *infos, tree_metadata_t *metadata,
		char *name);
#endif /* POST_PROCESSING */
