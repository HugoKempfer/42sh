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

static const post_processing_t POST_PROCESS[] = {
	{&is_backticks, &process_backticks};
	{&is_alias, &process_alias};
	{&is_variable, &process_variable};
	{&is_globings, &process_globings};
	{&is_double_coat, &process_double_coat};
	{&is_simple_coat, &process_simple_coat}
};

static llist_t *get_new_lexems(shell_info_t *infos, metadata_t *meta,
				char *data_command)
{
	int it = 0;
	llist_t *l_lexem = NULL;
	lnode_t *lexem = NULL;

	while (it < (int)ARR_SIZE(POST_PROCESS)) {
		if (POST_PROCESS[it].specific_command(infos), data_command) {
			l_lexem = POST_PROCESS[it].process_values(infos, meta);
			return (l_lexems);
		}
		it++;
	}
	return (NULL);
}

static void introduce_new_lexems(llist_t *new_lexems, lnode_t *lexem)
{
	lnode_t *tmp = lexem->next;

	lexem->next = new_lexems->head;
	if (tmp) {
		tmp->prev = new_lexems->tail;
	}
	free(new_lexems);
}

static char **update_command(shell_info_t *infos, metadata_t *metadata,
			char **command_str)
{
	llist_t *command = arr_dup_to_list(command_data);
	lnode_t lexem = command->head;
	llist_t *new_lexems = NULL;

	destroy_str_array(command_data);
	while (lexem) {
		new_lexems = get_new_lexems(infos, metadata, lexem->str);
		if (new_lexems) {
			list_pop(lexem, command);
			lexem = new_lexems->head;
			introduce_new_lexems(new_lexems, lexem);
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
