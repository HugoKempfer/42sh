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
#include "string.h"
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>

void print_tree(tnode_t *head);

static const post_processing_t POST_PROCESS[] =
{
//	{&is_backticks, &process_backticks};
//	{&is_variable, &process_variable};
	{&is_globings, &process_globings},
	{&is_double_coat, &process_coats},
	{&is_simple_coat, &process_coats}
};

static void print_list(llist_t *list)
{
	lnode_t *node = list->head;

	while (node) {
		printf("[%s]\n", (char *)node->data);
		node = node->next;
	}
}

static int get_new_lexems(shell_info_t *infos, tree_metadata_t *meta,
			       char *lexem, llist_t **l_lexem)
{
	int it = 0;
	int size_tab = ARRAY_SIZE(POST_PROCESS);
	while (it < size_tab) {
		if (POST_PROCESS[it].command_analyser(infos, lexem) == true) {
			printf("ok command analyser a return true\n");
			*l_lexem = POST_PROCESS[it].process_values(infos, meta, lexem);
			return (*l_lexem) ? true : false;
		}
		it++;
	}
	*l_lexem = NULL;
	return (true);
}

static void introduce_new_lexems(llist_t *command, llist_t *new_lexems, lnode_t *lexem)
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
	llist_t *command = arr_dup_to_list(command_str);
	lnode_t *lexem = command->head;
	llist_t *new_lexems = NULL;

	destroy_str_array(command_str);
/*	if (!introduce_alias(infos, lexem))
	return (false);*/
	while (lexem) {
		if (!get_new_lexems(infos, metadata, lexem->data, &new_lexems))
			return (NULL);
		if (new_lexems) {
			command->nb_nodes += new_lexems->nb_nodes;
			introduce_new_lexems(command, new_lexems, lexem);
			list_pop(lexem, command);
			lexem = new_lexems->tail;
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

int tree_post_process(shell_info_t *infos, tree_metadata_t *metadata,
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

int trees_post_processing(shell_info_t *infos, tree_metadata_t *metadata,
			tnode_t *tree_node)
{
	llist_t *trees_list = infos->processes;
	lnode_t *tree = trees_list->tail;
	tree_metadata_t *meta_tree = NULL;
	int compteur = 0;

	while (tree) {
		printf("%d\n", ++compteur);
		meta_tree = tree->data;
		printf("________________________\n");
		print_tree(meta_tree->head);
		printf("________________________\n");
		if (!tree_post_process(infos, metadata, meta_tree->head)) {
			return (false);
		}
		printf("________________________\n");
		print_tree(meta_tree->head);
		printf("________________________\n");
		tree = tree->prev;
	}
	return (true);
}
