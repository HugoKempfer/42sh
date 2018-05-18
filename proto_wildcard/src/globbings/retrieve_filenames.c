/*
** EPITECH PROJECT, 2018
** file ordering
** File description:
** retriev and sort the files
*/

#include "my.h"
#include "functions.h"
#include <dirent.h>

static void sync_sort_with_new_array(char **sorted, char **name_save, int limit)
{
	char **result = NULL;
	int name_idx = 0;
	int idx = 0;
	//int error_state = SUCCESS;

	limit++;
	result = malloc(sizeof(char *) * limit);
	while (name_idx != limit) {
		while (sorted[name_idx][0] != name_save[idx][0]) {
			idx++;
		}
		result[name_idx] = NULL;
		result[name_idx] = malloc(sizeof(char) * len_s(name_save[idx]));
		result[name_idx] = my_strcpy(result[name_idx], name_save[idx]);
		idx = 0;
		name_idx++;
	}
	idx = 0;
	while (idx != limit) {
		puts(result[idx]);
		my_putchar('\n');
		idx++;
	}
	//result[name_idx] = NULL;
	wilcard_manager(NULL, result);
	//error_save(error_state);
}

static char **fill_2d_array(char **filename, int limit)
{
	char **name_save = NULL;
	int idx = 0;

	name_save = malloc(sizeof(char *) * limit);
	while (idx != limit) {
		name_save[idx] = NULL;
		name_save[idx] = malloc(sizeof(char) * len_s(filename[idx]));
		name_save[idx] = my_strcpy(name_save[idx], filename[idx]);
		idx++;
	}
	return (name_save);
}

static void sort_the_grid(char **filename, int limit)
{
	int idx = 0;
	char save = 'c';
	char **name_save = NULL;

	name_save = fill_2d_array(filename, limit);
	limit = limit - 1;
	while (is_sorted(filename, limit) != 1) {
		while (idx != limit) {
			if (filename[idx][0] > filename[idx + 1][0]) {
				save = filename[idx][0];
				filename[idx][0] = filename[idx + 1][0];
				filename[idx + 1][0] = save;
			}
			++idx;
		}
		idx = 0;
	}
	sync_sort_with_new_array(filename, name_save, limit);
}

static int scan_the_files(DIR *dir, struct dirent *file, char **name, int nbr)
{
	int idx = 0;

	errno = 0;
	file = readdir(dir);
	while (file != NULL) {
		if (name != NULL && file->d_name[0] != '.') {
			name[idx] = malloc(sizeof(char) * len_s(file->d_name));
			name[idx] = my_strcpy(name[idx], file->d_name);
			//printf("%s\n", file->d_name);
			idx++;
		}
		nbr++;
		file = readdir(dir);
		if (errno != 0)
			exit(84);
	}
	closedir(dir);
	if (name != NULL) {
		name[idx] = NULL;
		wilcard_manager(NULL, name);
	}
		//sort_the_grid(name, idx);
	return (nbr);
}

int retrieve_the_files(void)
{
	DIR *dir = opendir("./src/globbings/");
	struct dirent *file = NULL;
	char **name = NULL;
	static int name_nbr = 0;

	if (dir == NULL)
		return (ERROR);
	if (name_nbr != 0)
		name = malloc(sizeof(char *) * name_nbr);
	if (dir != NULL && name_nbr == 0) {
		name_nbr = scan_the_files(dir, file, name, name_nbr);
		retrieve_the_files();
	}
	else if (dir != NULL) {
		name_nbr = scan_the_files(dir, file, name, name_nbr);
	}
	else
		return (ERROR);
	return (SUCCESS);
}