/*
** EPITECH PROJECT, 2018
** strcmp
** File description:
** cpoolday
*/

int my_strcmp_key(char const *s1, char const *s2, int n)
{
	int i = 0;
	int j = 0;

	while (s1[i] == '-') {
		i++;
	}
	while (s1[i] != '\0' && s2[j] != '\0' && s1[i] == s2[j] && i < n) {
		i++;
		j++;
	}
	return (s1[i] - s2[j]);
}
