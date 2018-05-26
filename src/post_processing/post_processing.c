/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** post_processing
*/

#include "42sh.h"
#include "metadata.h"
#include "post_processing.h"
#include "tools.h"
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>

static const post_processing_t POST_PROCESS[] =
{
//	{&is_backticks, &process_backticks};
//	{&is_variable, &process_variable};
	{is_globings, process_globings},
	{&is_double_coat, &process_coats},
	{&is_simple_coat, &process_coats}
};

static int get_new_lexems(shell_info_t *infos, tree_metadata_t *meta,
			       char *lexem, llist_t **l_lexem)
{
	int it = 0;

	while (it < (int)ARRAY_SIZE(POST_PROCESS)) {
		if (POST_PROCESS[it].command_analyser(infos, lexem)) {
			*l_lexem = POST_PROCESS[it].process_values(infos, meta, lexem);
			return (*l_lexem) ? true : false;
		}
		it++;
	}
	return (true);
}

static void introduce_new_lexems(llist_t *new_lexems, lnode_t *lexem)
{
	lnode_t *tmp = lexem->next;

	lexem->next = new_lexems->head;
	if (tmp) {
		tmp->prev = new_lexems->tail;
	}
}
/*
static int introduce_alias(shell_info_t *infos, lnode_t *lexem)
{
	llist_t *new_lexem = NULL;

	if (is_alias(infos, lexem)) {
		new_lexem = process_alias(infos, lexem->data);
		if (!new_lexem) {
			return (false);
		}
		introduce_new_lexems(new_lexem, lexem);
		list_pop(lexem, new_lexem);
		lexem = new_lexem->tail->next;
		free(new_lexem);
	}
	return (true);
}
*/
static char **update_command(shell_info_t *infos, tree_metadata_t *metadata,
			char **command_str)
{
	llist_t *command = arr_dup_to_list(command_data);
	lnode_t lexem = command->head;
	llist_t *new_lexems = NULL;

	destroy_str_array(command_data);
//	introduce_alias(infos, lexem);
	while (lexem) {
		get_new_lexems(infos, metadata, lexem->str, &new_lexems);
		if (new_lexems) {
			introduce_new_lexems(new_lexems, lexem);
			list_pop(lexem, command);
			lexem = new_lexems->tail;
			free(new_lexems);
		}
		lexem = lexem->next;
	}
	return (list_to_arr(command));
}

int post_processing(shell_info_t *infos, metadata_t *metadata,
			tnode_t *tree_node)
{
	char **command = NULL;
	enum tnode_type type;

	while (tree_node) {
		type = (tree_node->left) ? tree_node->left->data->type : -1;
		if (tree_node->left && type == COMMAND) {
			command = tree_node->left->data->str;
			command = update_command(infos, metadata, command);
		}
		type = (tree_node->left) ? tree_node->right->data->type : -1;
		if (tree_node->right && type == COMMAND) {
			command = tree_node->right->data->str;
			command = update_command(infos, metadata, command);
		}
		tree_node = tree_node->left;
	}
}
