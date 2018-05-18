/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** Exec binary
*/

#include "string.h"
#include <stdio.h>
#include <stdbool.h>
#include <stddef.h>
#include <unistd.h>

static const char *BASE_PATH[] = {
	"/bin",
	"/usr/bin",
	"/usr/local/bin"
};

/* Create the list of binary path from the env er by default bin path */
static char **get_binary_path(char *binary, shell_info_t *infos)
{
	char **path;
	char *env_path = env_get_value("PATH");
	char *tmp;
	int it = 0;

	path = env_path ? subdivise_str(env_path) : BASE_PATH;
	if (!path) {
		return (NULL);
	}
	while (it < ARR_SIZE(BASE_PATH)) {
		tmp = path[it];
		path[it] = str_concat((char *[]){path[it], "/", binary});
		free(tmp);
		if (!path[it]) {
			return (NULL);
		}
		++it;
	}
	return (path);
}

/* Check if at least one of the path is valid */
static char *get_binary_access(char *binary_name, shell_info_t *infos)
{
	char **binary_path = get_binary_path(binary_name);
	char **ptr = binary_path;
	char *valid_access = NULL;

	if (!binary_path) {
		return (NULL);
	}
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
	destroy_str_arr(binary_name);
	return (valid_access);
}

static void update_info(pid_t pid, shell_info_t *infos, tree_metadata *meta)
{
	meta->pid = pid;
	meta->state = ACTIVE;
}

static int get_ps_status(pid_t pid, shell_info_t *infos, tree_metadata_t *meta)
{
	int status;

	if (!(meta->is_job)) {
		waitpid(pid, &status, 0);
		meta->state = TERMINATED;
	} else {

		return (false);
	}
	if (WIFEXITED(status)) {
		meta->exit_code = WIEXITSTATUS(status);
		return (true);
	}
	else if (WISIGNALED(status)) {
		return (handle_ps_errors(pid, infos, meta));
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
		return ();
	}
	if (!env) {
		return (-1);
	}
	pid = fork();
	update_info(pid, infos, meta);
	if (!child_pid) {
		execve(binary_path, command, env);
	}
	return (get_process_status(pid, infos, meta)).
}
