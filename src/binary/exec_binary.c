/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** Exec binary
*/

#include "42sh.h"
#include "binary_exec.h"
#include "metadata.h"
#include "string.h"
#include "shell_path.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stddef.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stddef.h>

static const char SEPARATORS[] = {':', '\n', '\0', -1};
static const char KEPT[] = {-1};
static const char *SURROUNDINGS[] = {NULL};
static char *BASE_PATH[] = {
	"/bin",
	"/usr/bin",
	"/usr/local/bin",
	NULL
};

/* Create the list of binary path from the env by default bin path */
static char **get_binary_path(char *binary, shell_info_t *infos)
{
	char **path;
	char *env_path = env_get_value(infos->env, "PATH");
	char *tmp;
	int it = 0;
	cutter_charset_t charset = {SEPARATORS, KEPT, SURROUNDINGS};

	path = (env_path ? subdivise_str(env_path, charset) : BASE_PATH);
	while (path[it]) {
		tmp = path[it];
		path[it] = str_concat((char *[]){path[it], "/", binary, NULL});
		path != BASE_PATH ? free(tmp) : 0; //TODO change this shit
		if (!path[it]) {
			return (NULL);
		}
		++it;
	}
	return (path);
}

/* Check if at least one of the path is valid */
char *get_binary_access(char *binary_name, shell_info_t *infos)
{
	char **binary_path = get_binary_path(binary_name, infos);
	char **ptr = binary_path;
	char *valid_access = NULL;

	if (!binary_path) {
		return (NULL);
	}
	print_dbl_tab(binary_path);
	while (*ptr) {
		if (!access(*ptr, X_OK)) {
			valid_access = strdup(*ptr);
			break;
		}
		++ptr;
	}
	if (!access(binary_name, X_OK)) {
		valid_access = binary_name;
	}
	//destroy_str_array(binary_path);
	return (valid_access);
}

void update_info(pid_t pid, shell_info_t *infos, tree_metadata_t *meta)
{
	meta->pid = pid;
	meta->state = ACTIVE;
}

int get_ps_status(pid_t pid, shell_info_t *infos, tree_metadata_t *meta)
{
	int status = 0;

	printf("META [%p]\n", meta);
	if (!(meta->is_job)) {
		waitpid(pid, &status, 0);
	} else {
		return (false);
	}
	if (WIFEXITED(status)) {
		meta->return_code = WEXITSTATUS(status);
		return (true);
	}
	if (WIFSIGNALED(status)) {
		return (handle_ps_errors(status, infos, meta));
	}
	return (false);
}

int exec_binary(char **command, shell_info_t *infos, tree_metadata_t *meta)
{
	pid_t child_pid;
	char *binary_path = get_binary_access(*command, infos);
	char **env = list_to_arr(infos->env);

	if (!binary_path) {
		fprintf(stderr, "%s: Command not found.\n", *command);
		return (false);
	}
	if (!env) {
		return (-1);
	}
	child_pid = fork();
	if (!child_pid) {
		execve(binary_path, command, env);
		return (false);
	}
	update_info(child_pid, infos, meta);
	free(env);
	return (get_ps_status(child_pid, infos, meta));
}
