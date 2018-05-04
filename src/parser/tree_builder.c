/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** Functions to build the binary tree from the tokens
*/

#include "tools.h"
#include "binary_tree.h"
#include "list.h"
#include "lexer.h"
#include "parser.h"
#include "42sh.h"

static tree_metadata_t *init_tree_metadata(void)
{
	tree_metadata_t *metadata = malloc(sizeof(*metadata));

	if (!(metadata)) {
		return (NULL);
	}
	return (metadata);
}

static int build_tree(llist_t *tokens, shell_info_t *shell_info)
{
	tree_metadata_t *metadata = init_tree_metadata();
	tnode_t *head = create_tnode((tnode_data_t){TREE_HEAD, NULL});

	if (!(metadata) || !(head)) {
		free(metadata);
		free(head);
		return (false);
	}
	metadata->head = head;
	if (!(build_separator_branch(tokens, shell_infos, head))) {
		return (false);
	}
	if (!(add_expressions_branch(tokens, head))) {
		return (false);
	}
	metadata->tree_type = ((token_t *)tokens->tail->data)->type;
	list_pop(tokens->tail, tokens);
	return (true);
}

int build_trees_from_tokens(llist_t *tokens, shell_info_t *shell_info)
{
	while (!(tokens->nb_nodes)) {
		if (!(build_tree(tokens, shell_info))) {
			return (false);
		}
	}
	return (true);
}
