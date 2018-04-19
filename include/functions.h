/*
** EPITECH PROJECT, 2018
** function.h
** File description:
** common header, and config.
*/

#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_
#include <stdlib.h>
#include <stdbool.h>
#include <errno.h>

/* user_guide */
void user_guide_manager(char **av);

/* file_sorting */
int	retrieve_the_files(void);
int	is_sorted(char **filename, int limit);
void	print_the_grid_known_limit(char **filename, int limit);
int	print_tetriminos_metadata(char **result, int limit);
void	my_putstr_up_to_letter(char const *str, char const letter);
char	*get_path(char **result, int limit);
char	**get_2d_array_from_file(char *path, char **grid, char *buffer);
int	parameter(int ac, char **av);
int	display_size(char **av);
int	annulation(char **av, int travel);
int	display_next(char **av);
void    display_map(void);
char	*my_calloc(char *str, int size);
char	**my_2d_calloc(char **grid, int size);
char	*my_full_calloc(char *str, int size);
char	**my_full_2d_calloc(char **grid, int size);
int	check_size(char **grid);
int	error_save(int error_state);

/* maze_solving */
char **solver_scheduler(char **maze, size_t line_idx);

/* macros */
#define SUCCESS			0
#define ERROR			-1
#define GO_RIGHT		1
#define GO_LEFT			2
#define GO_HIGH			3
#define GO_DOWN			4

/* Attributes polymorphism with _generic*/
#define unused			__attribute__((unused))
/* specify that a function parameter must be non_null, 1, 2 syntax */
#define NON_NULL		__attribute__((non_null(1)))
#define transparent_union	__attribute__((__transparent_union__))

#endif
