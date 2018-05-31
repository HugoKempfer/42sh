/*
** EPITECH PROJECT, 2018
** var.h
** File description:
** structure for accessing variables and their corresponding value
*/

#ifndef MY_VAR_H
#define MY_VAR_H

#include "list.h"
#include "42sh.h"
#include <stdbool.h>
#include <stdlib.h>

typedef struct var_s var_t;

struct var_s
{
	char const *name;
	char const *value;
};

int	set_var(shell_info_t *info, char **name_or_value);
int	remove_var(shell_info_t *info, char **name_or_value);
var_t	*init_struct_var(char const *name, const char *value);
llist_t	*create_var_list(void);
int	var_manager(shell_info_t *info, char **command);
void	print_the_var(lnode_t *node, char **command);
void	print_the_list(shell_info_t *info);
llist_t	*retrieve_the_node(llist_t *var_list, char *name);
llist_t *process_value(llist_t *var_list, char *name);
lnode_t *find_node_var(llist_t *var_list, char *name);
size_t	grid_len(char **grid);
int	is_setting_the_var(char **cmd, char **value, shell_info_t *info);
int	is_alpha_num(char *str);

#endif /* MY_VAR_H */