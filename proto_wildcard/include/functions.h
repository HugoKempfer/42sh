/*
** EPITECH PROJECT, 2018
** function.h
** File description:
** common header, and config.
*/

#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

#include <stdlib.h>
#include <stdbool.h>
#include <errno.h>
#include "tools.h"

/* user_guide */

/* file_retrieving_and_sorting */
int	is_sorted(char **filename, int limit);
int	retrieve_the_files(void);

/* macros */
#define NO_ERR		1
#define ERR		0
#define FAILURE		-1


/* globbings */
bool	wilcard_manager(char **av, char **sorted_files);

/* Attributes polymorphism with _generic*/
#define unused			__attribute__((unused))
/* specify that a function parameter must be non_null, 1, 2 syntax */
#define NON_NULL		__attribute__((non_null(1)))
#define transparent_union	__attribute__((__transparent_union__))

#endif
