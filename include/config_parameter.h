/*
** EPITECH PROJECT, 2018
** struct
** File description:
** config parameter
*/

#include <getopt.h>

struct option optionel[] = {
	{"key-left", 1, 0, 'l'},
	{"key-right", 1, 0, 'r'},
	{"key-turn", 1, 0, 't'},
	{"key-drop", 1, 0, 'd'},
	{"key-quit", 1, 0, 'q'},
	{"key-pause", 1, 0, 'p'},
	{"without-next", 1, 0, 'w'},
	{"level", 1, 0, 'L'},
	{"map-size", 1, 0, 0},
	{0, 0, 0, 0}
};

struct option optionel_defaul[] = {
	{"left arrow", 1, 0, 'l'},
	{"right arrow", 1, 0, 'r'},
	{"top arrow", 1, 0, 't'},
	{"down arrow", 1, 0, 'd'},
	{"q", 1, 0, 'q'},
	{"space bar", 1, 0, 'p'},
	{"false", 1, 0, 'w'},
	{"1", 1, 0, 'L'},
	{"20*10", 1, 0, 0},
	{0, 0, 0, 0}
};

struct display {
	char *letter;
};

const struct display display_parameter[] =
{
	{"Key Left : "},
	{"Key Right : "},
	{"Key Turn : "},
	{"Key Drop : "},
	{"Key Quit : "},
	{"Key Pause : "},
	{"Next : "},
	{"Level : "},
	{"Size : "},
	{NULL}
};
