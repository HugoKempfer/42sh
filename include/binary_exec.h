/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** Functions to exec a binary and handle the error management
*/

#ifndef BINARY_EXEC_H
#define BINARY_EXEC_H

#include "42sh.h"
#include "metadata.h"

//typedef struct builtin_index_s builtin_index_t;
//typedef int (built_in_fptr)(shell_info_t *, char **);
//
//struct builtin_index_t {
//	*built_in_fptr fptr;
//	char name[32];
//};
//
int exec_binary(char **command, shell_info_t *infos, tree_metadata_t *meta);
int handle_ps_errors(int status, shell_info_t *infos, tree_metadata_t *meta);
char *get_binary_access(char *binary_name, shell_info_t *infos);

#endif /* ifndef BINARY_EXEC_H */
