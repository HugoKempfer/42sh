/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** Exit builtin functions
*/

#include "built_in_exec.h"
#include "tools.h"
#include <unistd.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int my_exit(shell_info_t unused *infos, char unused **command)
{
	exit(0);
}
