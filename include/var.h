/*
** EPITECH PROJECT, 2018
** var.h
** File description:
** structure for accessing variables and their corresponding value
*/

#ifndef MY_VAR_H
#define MY_VAR_H

#include "list.h"

typedef struct var_s var_t;

struct var_s
{
	char const *name;
	char const *value;
};

bool	set_var(llist_t *var_list, const char *name, const char *value);
bool	remove_var(llist_t *var_list, const char *name);
var_t	*init_struct_var(char const *name, const char *value);
llist_t	*create_var_list(void);
int	var_manager(char **command, llist_t *var_list);
void	print_the_var(lnode_t *node, char **command);
llist_t	*retrieve_the_node(llist_t *var_list, char *name);
llist_t *process_value(llist_t *var_list, char *name);
lnode_t *find_node_var(llist_t *var_list, char *name);

#endif /* MY_VAR_H */