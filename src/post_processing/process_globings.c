/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** process_globings
*/

#include "list.h"
#include <stdio.h>
#include <glob.h>

llist_t *process_globings(unused shell_info_t *infos,
			  unused tree_metadata_t *meta, char *str)
{
	glob_t paths;
	int it = 0;

	glob(str, 0, NULL, &paths);
	if (paths.gl_pathc == 0) {
		fprintf(stderr, "%s: No match.", str);
		return (0);
	}
	globfree(&paths);
	return (arr_to_list(paths.gl_pathv));
}
