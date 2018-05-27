/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** specific surondings
*/

#include "42sh.h"
#include "list.h"
#include "metadata.h"
#include "tools.h"
#include "post_processing.h"
#include "alias.h"
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>

int is_surrondings(char *str, char c)
{
	if (*str == c && *(str + (strlen(str) - 1)) == c) {
		return (true);
	}
	return (false);
}

int is_double_coat(unused shell_info_t *infos, char *lexem)
{
	if (is_surrondings(lexem, '"')) {
		return (true);
	}
	return (false);
}

int is_simple_coat(unused shell_info_t *infos, char *lexem)
{
	if (is_surrondings(lexem, '\'')) {
		return (true);
	}
	return (false);

}

int is_backticks(unused shell_info_t *infos, char *lexem)
{
	if (is_surrondings(lexem, '`')) {
		return (true);
	}
	return (false);
}
