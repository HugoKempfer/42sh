/*
** EPITECH PROJECT, 2018
** 42SH
** File description:
** Header for useful string management functions
*/

#ifndef STRING_H
#define STRING_H

#include <string.h>

typedef struct cutter_charset_s cutter_charset_t;

struct cutter_charset_s {
	char *separators;
	char *kept_separators;
	char **surroundings;
};

char **subdivise_str(char *, cutter_charset_t);
char *alloc_str(char *str);
void destroy_str_array(char **buffer);
int get_nb_lines(char **buffer);
char *alloc_n_str(char *str, int size);
char **add_line(char **buffer, char *line);
int get_end_of_str(const char *str, char *);
char *remove_surroundings(char *str);

#endif /* ifndef STRING_H */
