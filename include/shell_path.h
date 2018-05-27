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
path_t *init_shell_path(void);
lnode_t *env_get_node(llist_t *env, char *var_name);
void my_env(shell_info_t *infos, char **command);
int my_setenv(shell_info_t *infos, char **command);
void my_unsetenv(shell_info_t *infos, char **command);
int cd_management(shell_info_t *shell, char **command);
char *env_get_value(llist_t *env, char *var_name);

#endif /* ifndef SHELL_PATH */
