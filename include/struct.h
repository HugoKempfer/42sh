/*
** EPITECH PROJECT, 2017
** dante
** File description:
** struct.h
*/

#ifndef STRUCT_H_
# define STRUCT_H_

typedef struct map_s map_t;
typedef void (*wall)(int *, int);

struct map_s
{
	int height;
	int width;
	int *maze;
	wall *tab;
}

#endif //STRUCT_H_
