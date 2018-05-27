/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** process_globings
*/

#include "42sh.h"
#include "metadata.h"
#include "list.h"
#include "string.h"
#include "tools.h"
#include <stdio.h>
#include <glob.h>

llist_t *process_globings(unused shell_info_t *infos,
			  unused tree_metadata_t *meta, char *str)
{
	glob_t paths;

	glob(str, 0, NULL, &paths);
	if (paths.gl_pathc == 0) {
		fprintf(stderr, "%s: No match.", str);
		return (NULL);
	}
	return (arr_to_list(paths.gl_pathv));
}
