/*
** EPITECH PROJECT, 2018
** path.c
** File description:
** init path : "HOME, PWD, OLD_PWD"
*/

#include "42sh.h"
#include "shell_path.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>

path_t *init_shell_path(void)
{
	char *pwd = NULL;
	struct passwd *pw = NULL;
	path_t *shell_path;

	pwd = getcwd(NULL, 0);
	if (!pwd) {
		return (false);
	}
	pw = getpwuid(getuid());
	shell_path = malloc(sizeof(path_t));
	if (!pw || !shell_path) {
		return (false);
	}
	shell_path->home = pw->pw_dir;
	shell_path->pwd = pwd;
	shell_path->oldpwd = strdup(pwd);
	return (shell_path);
}
