/*
** EPITECH PROJECT, 2017
** 42sh
** File description:
** main.c
*/

#include "redirections.h"
#include "lexer.h"
#include "42sh.h"
#include "parser.h"
#include "my.h"
#include "strings.h"
#include "tools.h"
#include "metadata.h"
#include "post_processing.h"
#include "list.h"
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>

static void signal_handler(int handler)
{
	signal(SIGINT, signal_handler);
	write(1, "\n42sh> ", 7);
}

int main(int unused ac, char unused **av, char **env)
{
	shell_info_t *infos = init_shell_info(env);

	signal(SIGINT, signal_handler);
	shell_runtime(infos);
	return (0);
}
