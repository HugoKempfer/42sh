/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** post_processing
*/

#include "42sh.h"
#include "metadata.h"
#include "post_processing.h"
#include "alias.h"
#include "tools.h"
#include "str_manip.h"
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>

static const post_processing_t POST_PROCESS[] =
{
//	{&is_backticks, &process_backticks};
//	{&is_variable, &process_variable};
	{&is_alias, &process_alias},
	{&is_globings, &process_globings},
	{&is_double_coat, &process_coats},
	{&is_simple_coat, &process_coats}
};

int get_new_lexems(shell_info_t *infos, tree_metadata_t *meta,
			char *lexem, llist_t **l_lexem)
{
	int it = 0;
	int size_tab = ARRAY_SIZE(POST_PROCESS);

	while (it < size_tab) {
		if (POST_PROCESS[it].command_analyser(infos, lexem) == true) {
			*l_lexem =
			POST_PROCESS[it].process_values(infos, meta, lexem);
			return (*l_lexem) ? true : false;
		}
		it++;
	}
	*l_lexem = NULL;
	return (true);
}
