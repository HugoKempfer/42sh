/*
** EPITECH PROJECT, 2018
** Lemin
** File description:
** Function to manage the strings
*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "lexer_explicit.h"

int get_nb_lines(char **buffer)
{
	int it = 0;

	if (!(buffer)) {
		return (0);
	}
	while (buffer[it]) {
		it++;
	}
	return (it);
}

void destroy_str_array(char **buffer)
{
	int it = 0;

	while (buffer && buffer[it]) {
		free(buffer[it]);
		it++;
	}
	free(buffer);
}

char *alloc_str(char *str)
{
	size_t size = 0;
	size_t it = 0;
	char *output = NULL;

	while (str && str[size]) {
		++size;
	}
	output = malloc(sizeof(char) * (size + 1));
	if (!(output)) {
		return (NULL);
	}
	while (str && str[it]) {
		output[it] = str[it];
		it++;
	}
	output[it] = '\0';
	return (output);
}

char *alloc_n_str(char *str, int size)
{
	int it = 0;
	char *output = malloc(sizeof(char) * size + 2);

	if (!(output)) {
		return (NULL);
	}
	while (str && str[it] && it < size) {
		output[it] = str[it];
		it++;
	}
	output[it] = '\0';
	return (output);
}

char **add_line(char **buffer, char *line)
{
	int it = 0;
	int nb_lines = get_nb_lines(buffer);
	char **output = NULL;

	output = malloc(sizeof(char*) * (nb_lines + 2));
	if (!(output)) {
		destroy_str_array(buffer);
		return (NULL);
	}
	while (buffer && buffer[it]) {
		output[it] = buffer[it];
		it++;
	}
	output[it] = line;
	output[it + 1] = NULL;
	free(buffer);
	return (output);
}
