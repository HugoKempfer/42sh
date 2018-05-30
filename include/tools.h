/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** Useful tools
*/

#ifndef TOOLS_H
#define TOOLS_H

/* LibC includes */
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>
#include <unistd.h>

#define SUCCESS	0
#define ERROR	84

#define ARRAY_SIZE(a)	(sizeof(a) / sizeof(a[0]))
#define unused	__attribute__((unused))

int size_dbl_tab(char **);
#endif /* ifndef TOOLS_H */
