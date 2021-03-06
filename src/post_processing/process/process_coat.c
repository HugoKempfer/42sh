/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** process_coat : release " " and ' '
*/

#include "42sh.h"
#include "metadata.h"
#include "post_processing.h"
#include "list.h"
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>

char *release_surroundings(char *str)
{
	char *new_str = strndup(str + 1, (strlen(str) - 2));

	if (!new_str) {
		return (NULL);
	}
	return (new_str);
}

llist_t *process_coats(unused shell_info_t *infos,
			unused tree_metadata_t *metadata, char *lexem)
{
	llist_t *list = list_init(NULL);
	char *new_lexem = release_surroundings(lexem);

	if (!list || !new_lexem) {
		return (NULL);
	}
	if (!list_push_tail(new_lexem, list)) {
		return (NULL);
	}
	return (list);
}
