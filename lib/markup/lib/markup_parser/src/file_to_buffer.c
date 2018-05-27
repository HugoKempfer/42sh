/*
** EPITECH PROJECT, 2017
** file_to_buffer
** File description:
** Function to manage the data files
*/

#include <stdio.h>
#include <stddef.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "markup.h"

static int get_len(char *buffer)
{
	int it = 0;

	while (buffer[it] != '\0') {
		it++;
	}
	return (it);
}

static int my_strcpy(char *dest, char *src)
{
	int it = 0;
	int len = get_len(src);

	while (it != len) {
		dest[it] = src[it];
		it++;
	}
	dest[it] = '\0';
	return (it);
}

static char	*my_realloc(char *old, char *new, int size_old, int size_new)
{
	char *realloc_arr = NULL;
	int size = 0;

	realloc_arr = malloc(sizeof(char) * (size_old + size_new + 1));
	if (!(realloc_arr) || !(old)) {
		return (NULL);
	}
	size += my_strcpy(realloc_arr, old);
	if (new) {
		size += my_strcpy(&realloc_arr[size], new);
	}
	realloc_arr[size] = '\0';
	return (realloc_arr);
}

char *fill_buffer(char *path)
{
	int fd = open(path, O_RDONLY);
	char temp[DATA_RD_SIZE] = {0};
	char *buffer = NULL;
	char *ptr = NULL;

	if (fd == -1) {
		return (NULL);
	}
	while (read(fd, temp, DATA_RD_SIZE) == DATA_RD_SIZE || !buffer) {
		if (!(buffer)) {
			buffer = my_realloc(temp, NULL, get_len(temp), 0);
		} else {
			ptr = buffer;
			buffer = my_realloc(buffer, temp, get_len(buffer),
					get_len(temp));
			free(ptr);
		}
	}
	close(fd);
	return (buffer);
}
