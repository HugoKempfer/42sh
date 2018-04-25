/*
** EPITECH PROJECT, 2018
** 42SH
** File description:
** Header for useful string management functions
*/

#ifndef STRING_H
#define STRING_H

#include <strings.h>

typedef cutter_charset_s cutter_charset_t;

struct cutter_charset_s {
	char **separators;
	char **kept_separators;
};

char **subdivise_str(char *, cutter_charset_t *);

#endif /* ifndef STRING_H */
