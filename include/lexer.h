/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** Main header of the lexer
*/

#ifndef LEXER_H
#define LEXER_H

#include "metadata.h"
#include "binary_tree.h"
#include "list.h"
#include "tools.h"

typedef struct token_s token_t;
typedef struct token_type_list_s token_type_list_t;

#define T_SEP_min 1
#define T_SEP_max 3
#define CMD_SEP_min 4
#define CMD_SEP_max 8
#define SURROUND_MIN 9
#define SURROUND_MAX 10

/* Maccros to check if it's a separator  */
#define IS_TREE_SEPARATOR(a) ((a) >= T_SEP_min && (a) <= T_SEP_max)
#define IS_CMD_SEPARATOR(a) ((a) >= CMD_SEP_min && (a) <= CMD_SEP_max)
#define IS_SEPARATOR(a) ((a) >= SURROUND_MIN && (a) <= SURROUND_MAX)

/* Struct of the token itself */
struct token_s {
	enum tnode_type type;
	char **value;
};

/* Structure of the branch table */
struct token_type_list_s {
	char *str;
	enum tnode_type type;
};

llist_t *tokenize_command(char **command);
void destroy_token(void *data);

#endif /* ifndef LEXER_H */
