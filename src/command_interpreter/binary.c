/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** Execute binaries and redirect outputs to redirectors
*/

#include "redirections.h"
#include "binary_exec.h"
#include "binary_tree.h"
#include "42sh.h"
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static void exec_process(char **env, char *binary_path, char **command,
		int pipes[2])
{

	close(pipes.ps[1]);
	if (pipes[IN] != -1 && dup2(IN ,pipes[IN])) {
		return (false);
	}
	if (dup2(OUT, pipes[OUT]) == -1) {
		return;
	}
	execve(binary_path, command, env);
}

static int manage_ps(pid_t pid, shell_info_t *infos, tree_metadata_t *meta,
		int pipes[2])
{
	int status = get_ps_status(pid, infos, meta);

	close(pipes.ps[1]);
	return (status);
}

int redirection_exec_binary(tnode_t *cmd_node, tree_metadata_t *meta,
		shell_info_t *infos, int pipes[2])
{
	const char *binary_name = *(cmd_node->data.str);
	char *binary_path = get_binary_access(binary_name, infos);
	char **env = list_to_arr(infos->env);
	pid_t child_pid;

	if (!binary_path) {
		fprintf(stderr, "%s: Command not found.\n", binary_name);
		return (false);
	}
	if (!env) {
		return (-1);
	}
	child_pid = fork();
	if (!child_pid) {
		exec_process(env, binary_path, cmd_node->data.str, pipes);
		return (false);
	}
	free(env);
	free(binary_path);
	return (manage_ps(child_pid, infos, meta, pipes));
}
