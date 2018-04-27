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
	SEMI_COLON,
	AND,
	OR,
	NONE
};

enum exec_state
{
	ACTIVE,
	SUSPENDED
};

struct tree_metadata_s {
	tnode_t *head;
	bool is_job;
	pid_t pid;
	enum separator_type separator;
	enum exec_state state;
};

#endif /* ifndef METADATA_H */
