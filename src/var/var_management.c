/*
** EPITECH PROJECT, 2018
** var_management
** File description:
** manage the var funcs
*/

#include "functions.h"
#include "list.h"
#include "var.h"
#include "my.h"

char *find_value_var(llist_t *var_list, char *name)
{
	lnode_t *node = var_list->head;

	while (node) {
		if (!strcmp(name, ((var_t *)(node->data))->name)) {
			return (((var_t *)(node->data))->value);
		}
		node = node->next;
	}
	return (NULL);
}

llist_t *process_value(llist_t *var_list, char *name)
{
	llist_t *empty_list = list_init(NULL);
	char *value_var = find_value_var(var_list, name);

	if (!empty_list || !value_var) {
		return (NULL);
	}
	if (!list_push_tail(value_var, empty_list)) {
		return (NULL);
	}
	return (empty_list);
}

void print_the_list(lnode_t *tmp_node)
{
	my_putstr("PRINT_THE_LIST {\n");
	while (tmp_node) {
		my_putchar('\t');
		my_putstr(((var_t *)tmp_node->data)->name);
		my_putstr(" == ");
		puts(((var_t *)tmp_node->data)->value);
		tmp_node = tmp_node->next;
	}
	my_putstr("}\n");
}

void print_the_var(lnode_t *node, char **command)
{
	while (node) {
		if (!strcmp(&command[0][1], ((var_t *)node->data)->name)) {
			my_putstr(((var_t *)node->data)->name);
			my_putstr(" == ");
			puts(((var_t *)node->data)->value);
			return;
		}
		node = node->next;
	}
	my_putstr(&command[0][1]);
}

int var_manager(char **command, llist_t *var_list)
{
	lnode_t *tmp_node = var_list->head;

	if (!strcmp(command[0], "set") && !strcmp(command[2], "=")) {
		my_putstr("ON SET\n");
		if (!set_var(var_list, command[1], command[3])) {
			return (84);
		}
	}
	else if (!strcmp(command[0], "unset")) {
		my_putstr("UNSET\n");
		if (!remove_var(var_list, command[1])) {
			return (84);
		}
	}
	tmp_node = var_list->head;
	print_the_list(tmp_node);
	return (SUCCESS);
}