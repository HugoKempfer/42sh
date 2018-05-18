/*
** EPITECH PROJECT, 2018
** shell_path.h
** File description:
** structur used for (init env) and (init and management cd)
*/

#ifndef SHELL_PATH
#define SHELL_PATH

#include "42sh.h"

llist_t *init_list_env(char **base_env);
shell_path_t *init_shell_path(void);
lnode_t *env_get_node(llist_t *env, char *var_name);
int change_var_env(shell_path_t *cd_path, llist_t *env);

#endif /* ifndef SHELL_PATH */
