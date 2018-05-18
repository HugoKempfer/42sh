/*
** EPITECH PROJECT, 2017
** my_putstr
** File description:
** print a string
*/

void my_putchar(char c);

int my_putstr(char const *str)
{
	int i = 0;

	while (str[i] != '\0') {
		my_putchar(str[i]);
		i = i + 1;
	}
	return (0);
}
