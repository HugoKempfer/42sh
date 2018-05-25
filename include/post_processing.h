/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** post processing header
*/

#ifndef POST_PROCESSING_H
#define POST_PROCESSING_H

#include "42sh"
#include "liste.h"

typedef struct post_processing_s post_processing_t;

struct post_processing_s {
	int (*command_analyser)(shell_info_t *, char *);
	llist_t *(*process_values)(shell_info_t *, metadata_t *);
};

#endif /* POST_PROCESSING */
