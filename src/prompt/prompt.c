/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** Main file of the prompt
*/

#include "tools.h"

char *prompt(void)
{
	char *command = NULL;
	size_t len;

	fputs("42sh> ", stdout);
	if (getline(&command, &len, stdin) == -1) {
		free(command);
		return (NULL);
	}
	return (command);
}
