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

shell_path_t *init_shell_path(void)
{
	char *pwd = getcwd(NULL, 30);

	struct passwd *pw = getpwuid(getuid());
	shell_path_t *shell_path = malloc(sizeof(shell_path_t));

	shell_path->home = pw->pw_dir + 1;
	shell_path->pwd = pwd + 1;
	shell_path->old_pwd = pwd + 1;
	return (shell_path);
}
