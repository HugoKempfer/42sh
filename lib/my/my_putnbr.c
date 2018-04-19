/*
** EPITECH PROJECT, 2018
** my_putnbr
** File description:
** print a int
*/

void my_putchar(char c);

int my_putnbr(int number)
{
	if (number >= 10)
		my_putnbr(number / 10);
	if (number < 0) {
		number = number * -1;
		my_putchar('-');
		my_putnbr(number / 10);
	}
	my_putchar(((number % 10) + '0'));
}
