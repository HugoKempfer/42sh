/*
** EPITECH PROJECT, 2017
** dante
** File description:
** main.c
*/

#include <stdlib.h>
#include <stdio.h>
#include "my.h"
#include "functions.h"
#include "tools.h"

int main(int ac, char **av)
{
	if (ac == 2) {
		if (!(wilcard_manager(av, NULL))) {
			return (ERROR);
		}
	}
	return (0);
}
