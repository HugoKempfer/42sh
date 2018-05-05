/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** METADATA
*/

#ifndef METADATA_H
#define METADATA_H


#include "lexer.h"
#include "binary_tree.h"
#include "tools.h"
#include <sys/types.h>

typedef struct tree_metadata_s tree_metadata_t;

enum separator_type
{
	NONE,
	T_OR = 1,
	T_AND = 2,
	T_SEMI_COLON = 3
};

enum exec_state
{
	NOT_EXECUTED,
	ACTIVE,
	TERMINATED,
	SUSPENDED
};

struct tree_metadata_s {
	tnode_t *head;
	bool is_job;
	pid_t pid;
	enum separator_type tree_type;
	enum exec_state state;
};

#endif /* ifndef METADATA_H */
