/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** Header of te parsing functions
*/

#ifndef PARSER_H
#define PARSER_H

#include "lexer.h"
#include "42sh.h"
#include "binary_tree.h"
#include "list.h"

/* Function prototypes */
int build_trees_from_tokens(llist_t *tokens, shell_info_t *shell_info);
int build_separator_branch(llist_t *tokens, tnode_t *head);
int add_expressions_branch(llist_t *tokens, tnode_t *head);
int add_autonomous_cmd(tnode_t *head, llist_t *tokens);

#endif /* ifndef PARSER_H */
