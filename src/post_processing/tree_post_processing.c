/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** tree_post_processing principals function
*/

#include "42sh.h"
#include "metadata.h"
#include "post_processing.h"
#include "alias.h"
#include "tools.h"
#include "str_manip.h"
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>

void introduce_new_lexems(llist_t *command, llist_t *new_lexems,
				lnode_t *lexem)
{
	lnode_t *tmp = lexem->next;

	lexem->next = new_lexems->head;
	new_lexems->head->prev = lexem;
	if (tmp) {
		new_lexems->tail->next = tmp;
		tmp->prev = new_lexems->tail;
	}
	else {
		command->tail = new_lexems->tail;
	}
}

int introduce_alias(llist_t *command, lnode_t **lexem,
			shell_info_t *infos)
{
	llist_t *new_lexem = NULL;
	char *name = (*lexem)->data;

	if (is_alias(infos, name)) {
		new_lexem = process_alias(infos, name);
		command->nb_nodes += new_lexem->nb_nodes;
		introduce_new_lexems(command, new_lexem, *lexem);
		list_pop(*lexem, command);
		*lexem = new_lexem->head;
		free(new_lexem);
	}
	return (true);
}

static char **update_command(shell_info_t *infos, tree_metadata_t *metadata,
			char **command_str)
{
	llist_t *command = arr_dup_to_list(command_str);
	lnode_t *lexem = command->head;
	llist_t *new_lexems = NULL;

	destroy_str_array(command_str);
//	if (!introduce_alias(command, &lexem, infos))
//		return (false);
	while (lexem) {
		if (!get_new_lexems(infos, metadata, lexem->data, &new_lexems))
			return (NULL);
		if (new_lexems) {
			command->nb_nodes += new_lexems->nb_nodes;
			introduce_new_lexems(command, new_lexems, lexem);
			list_pop(lexem, command);
			lexem = new_lexems->head;
			free(new_lexems);
		}
		lexem = lexem->next;
	}
	return (list_to_arr(command));
}

static int process_node_command(tnode_t *son_node, shell_info_t *infos,
				tree_metadata_t *metadata)
{
	char **command = NULL;

	if (son_node && son_node->data.type == COMMAND) {
		command = update_command(infos, metadata, son_node->data.str);
		if (!command) {
			return (false);
		}
		son_node->data.str = command;
	}
	return (true);
}

int tree_post_processing(shell_info_t *infos, tree_metadata_t *metadata,
			tnode_t *tree_node)
{
	while (tree_node) {
		if (!process_node_command(tree_node->left, infos, metadata)) {
			return (false);
		}
		if (!process_node_command(tree_node->right, infos, metadata)) {
			return (false);
		}
		tree_node = tree_node->left;
	}
	return (true);
}
