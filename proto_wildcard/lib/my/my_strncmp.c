/*
** EPITECH PROJECT, 2018
** strncmp
** File description:
** ddec
*/

#include <stdio.h>
#include <stdbool.h>

int	my_strncmp(char const *s1, char const *s2, int n)
{
	int i = 0;

	while (s1[i] == s2[i] && i < n) {
		i++;
	}
	if (s1[i] == s2[i] && i == n) {
		return (true);
	}
	else {
		return (false);
	}
}
