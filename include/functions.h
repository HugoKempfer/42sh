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

/* user_guide */

/* file_sorting */
/* macros */

/* Attributes polymorphism with _generic*/
#define unused			__attribute__((unused))
/* specify that a function parameter must be non_null, 1, 2 syntax */
#define NON_NULL		__attribute__((non_null(1)))
#define transparent_union	__attribute__((__transparent_union__))

#endif
