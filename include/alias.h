/*
** EPITECH PROJECT, 2018
** alias.h
** File description:
** alias.h
*/

#ifndef ALIAS_H_
#define ALIAS_H_

#include "42sh.h"
#include "metadata.h"
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

int get_new_lexems(shell_info_t *infos, tree_metadata_t *meta,
		char *lexem, llist_t **l_lexem);
void introduce_new_lexems(llist_t *command, llist_t *new_lexems,
			lnode_t *lexem);
int introduce_alias(llist_t *command, lnode_t **lexem, shell_info_t *infos);
#endif /* ALIAS_H_ */
