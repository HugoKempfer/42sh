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
#include "list.h"
#include <stdlib.h>
#include <stdio.h>


char *prompt(void);
int process_manager(shell_info_t *infos);

static void print_da(char **arr)
{
	while (arr && *arr) {
		printf("[%s]\n", *arr);
		++(arr);
	}
}

int shell_runtime(shell_info_t *infos);

int main(int unused ac, char unused **av, char **env)
{
	shell_info_t *infos = init_shell_info(env);

	shell_runtime(infos);
	return (0);
}
