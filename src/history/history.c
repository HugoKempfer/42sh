/*
** EPITECH PROJECT, 2018
** history.c
** File description:
** history.c
*/

#include "42sh.h"
#include "list.h"
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int export_history(shell_info_t *infos)
{
	FILE *file = fopen("history", "a");
	llist_t *history = infos->history;
	lnode_t *node = history->tail;

	if (!file) {
		return (84);
	}
	while (node) {
		fwrite((char *)node->data, sizeof((char *)node->data), 1, file);
		fwrite("\n", 1, 1, file);
		node = node->next;
	}
	fclose(file);
	return (0);

}

int stock_history(shell_info_t *infos, char *str)
{
	llist_t *history = infos->history;

	if (!list_push_tail(str, history)) {
		return (false);
	}
	return (true);
}

char *last_line(shell_info_t *infos)
{
	llist_t *history = infos->history;

	return ((char *)history->tail->data);
}

