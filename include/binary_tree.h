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
	OR = 1,
	AND = 2,
	SEMI_COLON = 3,
	D_SUP = 4,
	D_INF = 5,
	PIPE = 6,
	SUP = 7,
	INF = 8,
	PARENTHESES = 9,
	BACK_TICKS = 10,
	COMMAND = 0,
	TREE_HEAD = -1
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
