/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** Main strucures of the shell
*/

#ifndef SH_H
#define SH_H

#include "list.h"

typedef struct shell_info_s shell_info_t;
typedef struct path_s path_t;

struct path_s {
	char *pwd;
	char *oldpwd;
	char *home;
};

struct shell_info_s {
	llist_t *processes;
	llist_t *special_vars;
	llist_t *local_vars;
	llist_t *env;
	llist_t *history;
	path_t *path;
};

shell_info_t *init_shell_info(char **base_env);

#endif /* ifndef SH_H */
