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

int is_globings(unused shell_info_t *infos, char *lexem);
int is_double_coat(unused shell_info_t *infos, char *lexem);
int is_simple_coat(unused shell_info_t *infos, char *lexem);
llist_t *process_globings(unused shell_info_t *infos,
			  unused tree_metadata_t *meta, char *str);
llist_t *process_coats(unused shell_info_t *infos,
		       unused tree_metadata_t *metadata, char *lexem);
int post_processing(shell_info_t *infos, tree_metadata_t *metadata,
		    tnode_t *tree_node);

#endif /* POST_PROCESSING */
