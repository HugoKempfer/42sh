/*
** EPITECH PROJECT, 2018
** glob.c
** File description:
** glob.c
*/

#include "list.h"
#include <stdio.h>
#include <glob.h>

llist_t *arr_to_list(char **buffer)
{
	llist_t *list = list_init(NULL);

	while (*buffer) {
		list_push_tail(*buffer, list);
		++buffer;
	}
	return (list);
}

llist_t *globings(char *str)
{
	glob_t paths;
	int it = 0;

	glob(str, 0, NULL, &paths);
	if (paths.gl_pathc == 0) {
		fprintf(stderr, "%s: No match.", str);
		return (0);
	}
//	globfree(&paths);
	return (arr_to_list(paths.gl_pathv));
}

