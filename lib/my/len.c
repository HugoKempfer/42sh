/*
** EPITECH PROJECT, 2018
** len
** File description:
** a shorter clone of my_strlen
*/

int len(char const *str)
{
	int length = 0;

	while (str[length] != '\0') {
		length = length + 1;
	}
	length = length + 1;
	return (length);
}
