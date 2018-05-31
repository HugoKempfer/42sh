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

	if (isatty(0)) {
		write(1, "42sh> ", 6);
	}
	if (getline(&command, &len, stdin) == -1) {
		free(command);
		return (NULL);
	}
	return (command);
}
