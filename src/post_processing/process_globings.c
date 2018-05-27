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
	int it = 0;
	printf("ayo on est dans globings\n");
	if (glob(str, 0, NULL, &paths) != 0) {
		printf("ERRRROOOOR\n");
		return (NULL);
	}
	if (paths.gl_pathc == 0) {
		fprintf(stderr, "%s: No match.", str);
		return (NULL);
	}
	return (arr_to_list(paths.gl_pathv));
}
