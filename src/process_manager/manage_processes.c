/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** Launch and manage all command trees
*/

#include "42sh.h"
#include "str_manip.h"
#include "metadata.h"
#include "post_processing.h"
#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>
#include <unistd.h>

int process_tree(shell_info_t *infos, tree_metadata_t *meta);

static lnode_t *get_next_tree(lnode_t *current, llist_t *ps)
{
	lnode_t *next_tree = current->next;
	tree_metadata_t *new_meta;
	tree_metadata_t *old_meta;

	if (!next_tree) {
		list_pop(current, ps);
		return (NULL);
	}
	new_meta = next_tree->data;
	old_meta = current->data;
	if (new_meta->tree_type == T_OR && !(old_meta->return_code)) {
		list_pop(next_tree, ps);
		return (get_next_tree(ps->head, ps));
	}
	if (new_meta->tree_type == T_AND && old_meta->return_code) {
		list_pop(next_tree, ps);
		return (get_next_tree(ps->head, ps));
	}
	list_pop(current, ps);
	return (next_tree);
}

static int execute_trees(shell_info_t *infos)
{
	lnode_t *current = infos->processes->head;
	int exec_state;

	while (current) {
		current = infos->processes->head;
		if (!tree_post_processing(infos, current->data,
		((tree_metadata_t *)(current->data))->head)) {
			return (false);
		}
		exec_state = process_tree(infos, current->data);
		current = get_next_tree(current, infos->processes);
		if (!exec_state) {
			return (false);
		}
	}
	return (true);
}

int process_manager(shell_info_t *infos)
{
	return (execute_trees(infos));
}
