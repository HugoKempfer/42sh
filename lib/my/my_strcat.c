/*
** EPITECH PROJECT, 2017
** my_strcat
** File description:
** Function who concatenates two strings.
*/

#include <stdlib.h>

int	my_strlen(char *str);

char	*my_strcat(char *dest, char *src)
{
	char *new;
	int i = 0;
	int j = 0;

	new = malloc(sizeof(char) * (my_strlen(dest) + my_strlen(src) + 1));
	while (dest[i] != '\0') {
		new[i] = dest[i];
		i++;
	}
	while (src[j] != '\0') {
		new[i] = src[j];
		i++;
		j++;
	}
	new[i] = '\0';
	return (new);
}
