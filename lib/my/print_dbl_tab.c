/*
** EPITECH PROJECT, 2018
** print_dbl_tab.c
** File description:
** print_dbl_tab and size_dbl_tab
*/

#include <stdio.h>

int size_dbl_tab(char **buffer)
{
	int size = 0;

	while (*buffer) {
		++(buffer);
		++size;
	}
	return (size);
}

void print_dbl_tab(char **buffer)
{
	printf("print dbl tab\n");
	while (buffer && *buffer) {
		printf("[%s]\n", *buffer);
		++(buffer);
	}
}
