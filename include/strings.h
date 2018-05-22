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
	const char *separators;
	const char *kept_separators;
	const char **surroundings;
};

char **subdivise_str(char *, cutter_charset_t);
char *alloc_str(char *str);
void destroy_str_array(char **buffer);
int get_nb_lines(char **buffer);
char *alloc_n_str(char *str, int size);
char **add_line(char **buffer, char *line);
int get_end_of_str(const char *str, const char *);
char *remove_surroundings(char *str);
char *str_concat(char **);

#endif /* ifndef STRING_H */
