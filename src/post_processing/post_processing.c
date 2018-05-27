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
			printf("on a affecté une liste\n");
			print_list(*l_lexem);
			return (*l_lexem) ? true : false;
		}
		it++;
	}
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
	if (!introduce_alias(infos, lexem)) {
		return (false);
	}
	while (lexem) {
		if (!get_new_lexems(infos, metadata, lexem->data, &new_lexems)) {
			return (false);
		}
		if (new_lexems) {
			command->nb_nodes += new_lexems->nb_nodes;
			introduce_new_lexems(command, new_lexems, lexem);
			list_pop(lexem, command);
			lexem = new_lexems->tail;
			free(new_lexems);
			new_lexems = NULL;
		}
		lexem = lexem->next;
	}
	return (list_to_arr(command));
}

int post_processing(shell_info_t *infos, tree_metadata_t *metadata,
			tnode_t *tree_node)
{
	char **command = NULL;
	enum tnode_type type;
	int compteur = 0;
	printf("%d\n", tree_node->left->data.type);
	while (tree_node) {
		type = (tree_node->left) ? tree_node->left->data.type : -1;
		if (tree_node->left && type == COMMAND) {
			print_dbl_tab(tree_node->left->data.str);
			command = tree_node->left->data.str;
			command = update_command(infos, metadata, command);
			if (!command) {
				printf("left est null\n");
				return (false);
			}
		}
		type = (tree_node->right) ? tree_node->right->data.type : -1;
		if (tree_node->right && type == COMMAND) {
			print_dbl_tab(tree_node->right->data.str);
			command = tree_node->right->data.str;
			command = update_command(infos, metadata, command);
			if (!command) {
				printf("right est null\n");
				return (false);
			}
		}
		printf("before changing tree branch\n");
		tree_node = tree_node->left;
	}
	return (true);
}
