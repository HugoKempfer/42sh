/*
** EPITECH PROJECT, 2018
** MiniShell
** File description:
** Advanced string concatainer
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static size_t get_total_size(char **str)
{
	size_t size = 0;
	int it = 0;

	while (str && str[it]) {
		size += strlen(str[it]);
		++it;
	}
	return (size);
}

char *concatainer(char **str)
{
	char *result = malloc(sizeof(char) * get_total_size(str));
	char *ptr = result;
	int it = 0;

	if (!(result)) {
		return (NULL);
	}
	while (*(str + it)) {
		strcpy(ptr, *(str + it));
		ptr += strlen(*(str + it));
		++it;
	}
	return (result);
}
