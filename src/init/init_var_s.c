/*
** EPITECH PROJECT, 2018
** init_var_s.c
** File description:
** init the var struct with linked lists
*/

#include "functions.h"
#include "list.h"
#include "var.h"

var_t *init_struct_var(char const *name, const char *value)
{
	var_t *var = malloc(sizeof(struct var_s) * 1);

	if (!var) {
		return (NULL);
	}
	if (name && value) {
		var->name = name;
		var->value = value;
	}
	return (var);
}

llist_t *create_var_list(void)
{
	llist_t *var_list = list_init(NULL);

	if (!var_list) {
		return (NULL);
	}
	return (var_list);
}
