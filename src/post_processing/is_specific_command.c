/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** is specific command ? specific commands are backticks, alias, variable,
** globings, " ", ' '.
*/

#include "42sh.h"
#include "metadata.h"
#include "tools.h"
#include "post_processing.h"
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>

int is_backticks(unused shell_info_t *infos, char *command)
{
	return (true);
}

int is_alias(shell_info_t *infos, char *command)
{
	return (true);
}

int is_variable(shell_info_t *infos, char *command)
{
	return (true);
}

int is_globings(unused shell_info_t *infos, char *command)
{
	return (true);
}

int is_double_coat(unused shell_info_t *infos, char *command)
{
	return (true);
}

int is_simple_coat(unused shell_info_t *infos, char *command)
{
	return (true);
}
