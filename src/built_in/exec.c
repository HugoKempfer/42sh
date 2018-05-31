/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** Exec built-ins
*/

#include "built_in_exec.h"
#include "tools.h"
#include <unistd.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

static const builtin_index_t BUILTINS[] = {
	{cd_management, "cd"},
	{my_setenv, "setenv"},
	{my_unsetenv, "unsetenv"},
	{my_env, "env"},
	{set_var, "set"},
	{remove_var, "unset"}
};

built_in_fptr *get_builtin_func(char *name)
{
	int it = 0;

	while (it < (int)ARRAY_SIZE(BUILTINS)) {
		if (!strcmp(name, BUILTINS[it].name)) {
			return (BUILTINS[it].fptr);
		}
		++it;
	}
	return (NULL);
}

