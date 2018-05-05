/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** Functions to build the binary tree from the tokens
*/

#include "binary_tree.h"
#include "42sh.h"
#include "lexer.h"
#include "list.h"
#include "parser.h"
#include "tools.h"

/* Init the tree metadata wrapper */
static tree_metadata_t *init_tree_metadata(void)
{
	tree_metadata_t *metadata = malloc(sizeof(*metadata));

	if (!(metadata)) {
		return (NULL);
	}
	return (metadata);
}

/* Build a whole command tree and push it into the process list */
static int build_tree(llist_t *tokens, shell_info_t *shell_info)
{
	tree_metadata_t *metadata = init_tree_metadata();
	tnode_t *head = create_tnode((tnode_data_t){TREE_HEAD, NULL});

	printf("BUILD TREE\n");
	if (!(metadata) || !(head)) {
		free(metadata);
		free(head);
		return (false);
	}
	metadata->head = head;
	printf("Build separator\n");
	if (!(build_separator_branch(tokens, head))) {
		return (false);
	}
	printf("Build expression\n");
	if (!(add_expressions_branch(tokens, head))) {
		return (false);
	}
	printf("After expression\n");
	metadata->tree_type = ((token_t *)tokens->tail->data)->type;
	list_pop(tokens->tail, tokens);
	list_push_head(metadata, shell_info->processes);
	return (true);
}

/* Loop the creation of command trees */
int build_trees_from_tokens(llist_t *tokens, shell_info_t *shell_info)
{
	while (tokens->nb_nodes) {
		if (!(build_tree(tokens, shell_info))) {
			return (false);
		}
	}
	return (true);
}
