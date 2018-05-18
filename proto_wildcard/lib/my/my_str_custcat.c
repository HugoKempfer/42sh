/*
** EPITECH PROJECT, 2017
** my_str_custcat
** File description:
** Function who concatenates two strings
*/

#include <stdlib.h>

int	my_strlen(char *str);

char	*str_custcat(char *dest, char *src)
{
	char cust = '/';
	char *new;
	int i = 0;
	int j = 0;

	new = malloc(sizeof(char) * (my_strlen(dest) + my_strlen(src) + 2));
	while (dest[i] != '\0') {
		new[i] = dest[i];
		i++;
	}
	new[i] = cust;
	i++;
	while (src[j] != '\0') {
		new[i] = src[j];
		i++;
		j++;
	}
	new[i] = '\0';
	return (new);
}
