/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** Handle the binary execution errors
*/

#include "str_manip.h"
#include "42sh.h"
#include "metadata.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stddef.h>
#include <signal.h>

int handle_ps_errors(int status, shell_info_t *infos, tree_metadata_t *meta)
{
	switch (WTERMSIG(status)) {
		case SIGSEGV:
			fprintf(stderr, "Segmentation fault\n");
			return (139);
		case SIGFPE:
			fprintf(stderr, "Floating exception\n");
			return (136);
		case SIGILL:
			fprintf(stderr, "Illegal instruction\n");
			break;
		default:
			break;
	}
	return (false);
}
