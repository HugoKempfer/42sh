/*
** EPITECH PROJECT, 2017
** dante
** File description:
** generator.h
*/

#ifndef GENERATOR_H_
#define GENERATOR_H_

#include <stdlib.h>
#include "struct.h"

int my_getnbr(char *str);

void generate_size_map(map_t *map);
void randomize_map(map_t *map, int *maze);

#endif /* GENERATOR_H_ */
