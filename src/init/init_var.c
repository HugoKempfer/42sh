/*
** EPITECH PROJECT, 2018
** init_var_s.c
** File description:
** init the var struct with linked lists
*/

#include "list.h"
#include "var.h"
#include <stdlib.h>

var_t *init_struct_var(char const *name, const char *value)
{
	var_t *var = malloc(sizeof(struct var_s) * 1);

	if (!var) {
		return (NULL);
	}
	var->name = name;
	var->value = value;
	return (var);
}
