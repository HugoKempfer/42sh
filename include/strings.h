/*
** EPITECH PROJECT, 2018
** 42SH
** File description:
** Header for useful string management functions
*/

#ifndef STRING_H
#define STRING_H

#include <string.h>
#include "list.h"

typedef struct cutter_charset_s cutter_charset_t;

struct cutter_charset_s {
	const char *separators;
	const char *kept_separators;
	const char **surroundings;
};

char **subdivise_str(char *, cutter_charset_t);
void destroy_str_array(char **buffer);
int get_nb_lines(char **buffer);
char *alloc_n_str(char *str, int size);
char **add_line(char **buffer, char *line);
int get_end_of_str(const char *str, const char *);
char *remove_surroundings(char *str);
char *str_concat(char **);
llist_t *arr_to_list(char **);
llist_t *arr_dup_to_list(char **);
char **list_to_arr(llist_t *);
void print_dbl_tab(char **);
#endif /* ifndef STRING_H */
