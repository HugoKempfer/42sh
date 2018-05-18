/*
** EPITECH PROJECT, 2018
** globs.c
** File description:
** Retrieve the corresponding string according to the wilcards rules.
*/

#include "my.h"
#include "functions.h"
#include <unistd.h>
#include <string.h>

ptrdiff_t my_strchr(char const *str, char const ascii_value)
{
	char const *addr_save = str;

	if (str[0] == '*') {
		return (NO_ERR);
	}
	while (*str && *(str++) != ascii_value);
	str--;
	if (*str == ascii_value) {
		return (str - addr_save);
	}
	else {
		return (ERR);
	}
}

bool is_last_char(char const *str, char const ascii_value)
{
	while (*str && *(str++) != ascii_value);
	str--;
	if (*str == ascii_value && !(*(++str))) {
		return (NO_ERR);
	}
	else {
		return (ERR);
	}
}

static bool other_wildcards_cases(char const *glob_str, char const *filename)
{
	char const *addr_save = filename;

	if (is_last_char(glob_str, '*') && \
		my_strncmp(glob_str, filename, my_strchr(glob_str, '*') - 1)) {
		printf("end_wildcard -> %s\n", filename);
	}
	else if (glob_str[0] != '*' && !(is_last_char(glob_str, '*')) && \
		my_strncmp(glob_str, filename, my_strchr(glob_str, '*') - 1)) {
		while (*filename && *(filename++) != \
			glob_str[my_strchr(glob_str, '*') + 1]);
		filename--;
		while (*(glob_str++) != '*');
		if (my_strcmp(glob_str, filename)) {
			printf("in_between -> %s\n", addr_save);
		}
	}
	else {
		return (ERR);
	}
	return (NO_ERR);
}

static char **joker_manager(char const *glob_str, char const *filename)
{
	char **wildcard_list = NULL;

	if (glob_str[0] == '*' && glob_str[1] == '\0') {
		printf("only_star -> %s\n", filename);//add_line
	}
	else if (my_strn_end_cmp(++glob_str, filename) && glob_str[-1] == '*') {
		printf("my_strn_end_cmp -> %s\n", filename);
	}
	else {
		--glob_str;
		other_wildcards_cases(glob_str, filename);//if (true) -> fill_list
	}
	return (wildcard_list);
}

bool wilcard_manager(char **av, char **filenames)
{
	static char *wildcard_str = NULL;
	size_t idx = 0;

	if (av && !filenames) {
		wildcard_str = malloc(sizeof(char) * len_s(av[1]));
		my_strcpy(wildcard_str, av[1]);
		retrieve_the_files();
	} else {
		while (filenames[idx]) {
			my_strchr(wildcard_str, '*') ? \
			joker_manager(wildcard_str, filenames[idx]) : 0;
			free(filenames[idx]);
			idx++;
		}
		free(filenames);
		free(wildcard_str);
	}
	return (NO_ERR);//pour les multiples wildcards, rappeler la fonction wildcard fois en passant au prochain wldcard.
}
//char ***
//refactorer pour scan each letters of glob_str
//d'*'c doesnt work were .c work (off by one ?)
//te'*'t
//retrieve'*'es.c