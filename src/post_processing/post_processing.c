/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** post_processing
*/

#include "42sh.h"
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>

int post_parsing_tree(tree_metadata_t *head)
{
	while (head) {
		if (head->left->type != COMMAND) {
			
		}
		head = head->left;
	}
}
