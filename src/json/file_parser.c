/*
** EPITECH PROJECT, 2017
** file_parser.c
** File description:
** Function to tokenize and parser a file into the data structure
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include "libstring.h"
#include "markup.h"

static mnode_t *alloc(mtoken_t *token, char *value, mtype_t type, mnode_t *root)
{
	mnode_t *node = NULL;
	char *label_b = alloc_str(token->token, my_strlen(token->token));
	char *value_b = alloc_str(value, my_strlen(value));

	if (!(label_b) || (value && !(value_b))) {
		free(label_b);
		free(value_b);
	}
	if (type == ROOT) {
		free(value_b);
		node = insert_node_tail(label_b, NULL, root);
	}
	else {
		node = insert_node_tail(label_b, value_b, root);
	}
	return (node);
}

static int fill_child(mnode_t *root, mtoken_t *token)
{
	int it = 0;
	mnode_t *ptr = NULL;

	if (!(IS_LABEL(token[0]))) {
		return (0);
	}
	while (token[it].token && !(IS_BLOCK_END(token[it]))) {
		if (IS_LABEL(token[it]) && IS_BLOCK_ENTRY(token[it + 1])) {
			ptr = alloc(token + it, NULL, ROOT, root);
			it += 2;
			it += fill_child(ptr, token + it);
		} else if (IS_LABEL(token[it]) && IS_VALUE(token[it + 2])) {
			alloc(token + it, token[it + 2].token, CHILD, root);
			it += 2;
		}
		it++;
	}
	return (it);
}

static mnode_t *create_tree(mnode_t *root, mtoken_t *token)
{
	int it = 0;

	fill_child(root, &token[it]);
	return (root);
}

mnode_t *parse_file(char *filepath)
{
	mnode_t *root = create_node("Root", ROOT);
	char *file = fill_buffer(filepath);
	mtoken_t *token = markup_lexer(file);

	if (!root || !file) {
		free(file);
		if (root) {
			free(root->data.root);
			free(root);
		}
		return (NULL);
	}
	root = create_tree(root, token);
	free(file);
	destroy_token_arr(token);
	return (root);
}
