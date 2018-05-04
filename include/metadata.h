/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** METADATA
*/

#ifndef METADATA_H
#define METADATA_H


#include <sys/types.h>
#include "tools.h"
#include "lexer.h"

typedef struct tree_metadata_s tree_metadata_t;

enum separator_type
{
	NONE,
	OR = 1,
	SEMI_COLON = 2,
	AND = 3
};

enum exec_state
{
	NONE,
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
