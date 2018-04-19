/*
** EPITECH PROJECT, 2017
** my_strlen
** File description:
** cpt_numbers
*/

int  my_strlen(char *str)
{
	int i = 0;

	while (str[i] != '\0') {
		i = i + 1;
	}
	return (i);
}
