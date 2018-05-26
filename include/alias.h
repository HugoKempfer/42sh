/*
** EPITECH PROJECT, 2018
** alias.h
** File description:
** alias.h
*/

#ifndef ALIAS_H_
#define ALIAS_H_

#include "list.h"
#include <stdbool.h>
#include <stddef.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct alias_s alias_t;

struct alias_s
{
	char *name;
	char *value;
};

lnode_t *get_the_node(llist_t *alias, char *str);
#endif /* ALIAS_H_ */
