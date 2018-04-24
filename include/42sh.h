/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** Main strucures of the shell
*/

#ifndef 42SH_H
#define 42SH_H

struct shell_info_s {
	llist_t *processes;
	llist_t *global_vars;
	llist_t *local_vars;
	llist_t *env;
};
#endif /* ifndef 42SH_H */
