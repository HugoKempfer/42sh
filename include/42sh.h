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
typedef struct shell_path_s shell_path_t;

struct shell_path_s {
	char *pwd;
	char *old_pwd;
	char *home;
};

struct shell_info_s {
	llist_t *processes;
	llist_t *global_vars;
	llist_t *local_vars;
	llist_t *env;
	shell_path_t path;
};

shell_info_t *init_shell_info(void);
#endif /* ifndef SH_H */
