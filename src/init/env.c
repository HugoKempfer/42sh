/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** Initialization of the env list
*/

#include "42sh.h"
#include "list.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

/* Example of the tcsh vars
 	HOSTTYPE=x86_64-linux
	VENDOR=unknownOSTYPE=linuxMACHTYPE=x86_64
	SHLVL=1
	PWD=/home/hugo
	LOGNAME=hugo
	USER=hugo
	GROUP=users
	HOST=DarkCake
	OLDPWD=/
	HOME=/home/
*/

static int copy_base_env(char **base_env, llist_t *env)
{
	lnode_t *var = env->head;

	while (base_env) {
		if (!list_push_tail(*base_env, env)) {
			return (false);
		}
		++base_env;
	}
	return (true);
}

int init_list(char **base_env, llist_t *env)
{
	if (!copy_base_env(base_env, env)) {
		return (false);
	}
	//TODO add base TCSH vars if not existing
	return (true);
}
