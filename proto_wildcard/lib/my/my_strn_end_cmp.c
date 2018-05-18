/*
** EPITECH PROJECT, 2018
** my_strn_cmp_end.c
** File description:
** compare begining by the end of the string, up to n chars
*/

#include "my.h"
#include <stdio.h>

bool my_strn_end_cmp(char const *s1, char const *s2)
{
	size_t idx_1 = 0;
	size_t idx_2 = 0;

	while (s2[(idx_2++) + 2]);
	while (s1[(idx_1++) + 2]);
	while (idx_1 != 0 && s1[idx_1] == s2[idx_2]) {
		idx_1--;
		idx_2--;
	}
	if (!idx_1 && s1[idx_1] == s2[idx_2]) {
		//printf("valid_filename : %s == *%s\n", s2, s1);
		return (true);
	}
	else {
		return (false);
	}
}//last_char
//testtttt