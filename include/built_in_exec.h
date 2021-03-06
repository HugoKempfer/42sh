/*
** EPITECH PROJECT, 2018
** 42h
** File description:
** header to exec built_in
*/

#ifndef BUILT_IN_EXEC_H
#define BUILT_IN_EXEC_H
#ifndef NTD
#define NTD 0
#include "42sh.h"

typedef int (built_in_fptr)(shell_info_t *, char **);
typedef struct builtin_index_s builtin_index_t;

struct builtin_index_s {
	built_in_fptr *fptr;
	char name[32];
};

int my_env(shell_info_t *infos, char **command);
int my_setenv(shell_info_t *infos, char **command);
int my_unsetenv(shell_info_t *infos, char **command);
int cd_management(shell_info_t *shell, char **command);
int add_alias(shell_info_t *infos, char **tab);
int set_var(shell_info_t *infos, char **command);
int remove_var(shell_info_t *infos, char **command);
int my_exit(shell_info_t *infos, char **command);
int my_echo(shell_info_t *infos, char **tab);
built_in_fptr *get_builtin_func(char *name);

#endif /* ifnedef BUILT_IN_EXEC_H */
#endif /* ifnedef NTD */
