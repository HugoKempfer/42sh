/*
** EPITECH PROJECT, 2018
** strncmp
** File description:
** ddec
*/

#include <stdio.h>

int	my_strncmp(char const *s1, char const *s2, int n)
{
	int i = 0;

	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i] && i < n) {
		i++;
	}
	return (s1[i] - s2[i]);
}
