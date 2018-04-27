/*
** EPITECH PROJECT, 2018
** MiniShell
** File description:
** Header for the binary tree
*/

#ifndef BINARY_TREE_H
#define BINARY_TREE_H

typedef struct tnode_data_s tnode_data_t;
typedef struct tnode_s tnode_t;

#define	LEFT 0
#define	RIGHT 1
#define	NOT_EXISTING 1
#define	EXISTING 2
#define	RIGHT 1

enum tnode_type
{
	PIPE,
	SUP,
	INF,
	D_SUP,
	D_INF,
	PARENTHESES,
	BACK_TICKS,
	AND,
	OR,
	COMMAND
};

struct tnode_data_s {
	enum tnode_type type;
	char **str;
};

struct tnode_s {
	tnode_t *right;
	tnode_t *left;
	tnode_data_t data;
};

#endif /* ifndef BINARY_TREE_H */
