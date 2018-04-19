/*
** EPITECH PROJECT, 2017
** my.h
** File description:
** Function prototypes of my library.
*/

#ifndef _MY_H
#define _MY_H
#include <unistd.h>

void	my_putchar(char c);
void	my_putchar_error(char c);
int	my_isneg(int nb);
int	my_put_nbr(int nb);
int	my_swap(int *a, int *b);
int	my_putstr(char const *str);
int	my_putstr_error(char const *str);
int	my_strlen(char *str);
int	my_getnbr(char const *str);
void	my_sort_int_array(int *tab, int size);
int	my_compute_power_rec(int nb, int power);
int	my_compute_square_root(int nb);
int	my_is_prime(int nb);
int	my_find_prime_sup(int nb);
char	*my_strcpy(char *dest, char const *src);
char	*my_strncpy(char *dest, char const *src, int n);
char	*my_revstr(char *str);
char	*my_strstr(char *str, char const *to_find);
int	my_strcmp(char const *s1, char const *s2);
int	my_strcmp(char const *str, char const *ref_str);
int	my_strncmp(char const *s1, char const *s2, int n);
char	*my_strupcase(char *str);
char	*my_strlowcase(char *str);
char	*my_strcapitalize(char *str);
int	my_str_isalpha(char const *str);
int	my_str_isnum(char const *str);
int	my_str_islower(char const *str);
int	my_str_isupper(char const *str);
int	my_str_isprintable(char const *str);
int	my_showstr(char const *str);
int	my_showmen(char const *str, int size);
char	*my_strcat(char *dest, char *src);
char	*my_strncat(char *dest, char const *src, int nb);
int	my_put_nbr_base(int nb, int j);
void	my_printf(char *s, ...);
int	is_alpha_num_2d(char **tab, int i, int y);
char	**str_toward_array(char *str);
char	**str_toward_array_space(char *str);
char	*str_custcat(char *dest, char *src);
int	my_getnbr(char const *str);
char	*first_line(char **av, char *mod, int av_nbr);
void	my_putnchar(char c, int n);
int	scheduler(int height, int matches_limit);
int	my_putnbr(int number);
char	**sched(int ac, char **av, int USER);
void	print_the_grid(char **grid);
int	len(char const *str);
int	my_strcmp_key(char const *s1, char const *s2, int n);

#endif
