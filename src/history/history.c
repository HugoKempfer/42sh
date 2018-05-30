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
	lnode_t *node = history->head;
	char *line = NULL;

	if (!file) {
		return (84);
	}
	while (node) {
		line = node->data;
		fwrite(line, strlen(line), 1, file);
		free(line);
		node = node->next;
	}
	free(line);
	fclose(file);
	return (0);
}

int stock_history(shell_info_t *infos, char *command)
{
	llist_t *history = infos->history;

	if (!list_push_tail(command, history)) {
		return (false);
	}
	return (true);
}

char *last_line(shell_info_t *infos)
{
	llist_t *history = infos->history;

	return ((char *)history->tail->data);
}
