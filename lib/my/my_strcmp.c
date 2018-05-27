/*
** EPITECH PROJECT, 2018
** strcmp
** File description:
** cpoolday
*/

int my_strcmp(char const *s1, char const *s2)
{
	int i = 0;
	int j = 0;

	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i]) {
		i++;
	}
	return (s1[i] - s2[i]);
}