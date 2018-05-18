/*
** EPITECH PROJECT, 2018
** my_putnchar
** File description:
** print n chars
*/

void my_putchar(char c);

void my_putnchar(char c, int n)
{
	while (n != 0) {
		my_putchar(c);
		n--;
	}
}
