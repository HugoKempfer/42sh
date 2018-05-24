/*
** EPITECH PROJECT, 2017
** file_to_buffer
** File description:
** Function to manage the data files
*/

#include <stddef.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "libstring.h"
#include "markup.h"

static int hugo_strcpy(char *dest, char *src)
{
	size_t it = 0;
	size_t len = my_strlen(src);

	while (it != len) {
		dest[it] = src[it];
		it++;
	}
	dest[it] = '\0';
	return (it);
}

static char *my_realloc(char *old, char *new)
{
	char *realloc_arr = NULL;
	int size = 0;
	size_t size_old = my_strlen(old);
	size_t size_new = my_strlen(new);

	realloc_arr = malloc(sizeof(char) * (size_old + size_new + 1));
	if (!(realloc_arr) || !(old)) {
		return (NULL);
	}
	size += hugo_strcpy(realloc_arr, old);
	if (new) {
		size += hugo_strcpy(&realloc_arr[size], new);
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
			buffer = my_realloc(temp, NULL);
		} else {
			ptr = buffer;
			buffer = my_realloc(buffer, temp);
			free(ptr);
		}
	}
	close(fd);
	return (buffer);
}
