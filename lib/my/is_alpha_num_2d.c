/*
** EPITECH PROJECT, 2018
** is_alpha_num_2d
** File description:
** alpha ou num switch
*/

int is_alpha_num_2d(char **tab, int i, int y)
{
	if ((tab[i][y] >= 65 && tab[i][y] <= 90) \
		|| (tab[i][y] >= 97 && tab[i][y] <= 122)) {
		return (1);
	}
	else if (tab[i][y] >= 48 && tab[i][y] <= 57)
		return (2);
	else
		return (0);
}
