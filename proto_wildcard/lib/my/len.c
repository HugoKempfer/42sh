/*
** EPITECH PROJECT, 2018
** len
** File description:
** my_strlen + '\0'
*/

#include <stdlib.h>

size_t len_s(char const *str)
{
	size_t length = 0;

	while (str[length] != '\0') {
		length = length + 1;
	}
	length = length + 1;
	return (length);
}
