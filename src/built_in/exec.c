/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** Exec built-ins
*/

#include "binary_exec.h"

static const builtin_index_t BUILTINS[] = {
	{cd, "cd"},
	{my_setenv, "setenv"},
	{my_unsetenv, "unsetenv"},
	{my_env, "env"},
	{setvar, "set_var"},
	{remove_var, "remove_var"}
};

builtin_index_t *get_builtin_func(char *name)
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

int exec_builtin(builtin_index_t *fptr, shell_info_t *infos, char **command)
{
	if (!fptr(infos, command)) {
		return (false);
	}
	return (true);

