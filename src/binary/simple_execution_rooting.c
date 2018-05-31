/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** Rooting execution table, without redirections
*/

#include "42sh.h"
#include "built_in_exec.h"
#include "built_in_exec.h"
#include "binary_exec.h"
#include "metadata.h"
#include "str_manip.h"
#include "shell_path.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stddef.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stddef.h>

int exec_binary(char **command, shell_info_t *infos, tree_metadata_t *meta);

int simple_exec_rooting(char **command, shell_info_t *infos,
		tree_metadata_t *meta)
{
	int state;
	built_in_fptr *builtin = get_builtin_func(*command);

	if (!builtin) {
		return (exec_binary(command, infos, meta));
	}
	state = builtin(infos, command);
	meta->return_code = (state) ? 0 : 1;
	return (state);
}
