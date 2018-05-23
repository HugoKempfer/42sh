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
		redirectors_pipes_t pipes)
{

	close(pipes.pfd[1]);
	if (dup2(pipes.pfd[0], 0) == -1 || dup2(pipes.parent_pfd[1], 1) == -1) {
		return;
	}
	execve(binary_path, command, env);
}

static int manage_ps(pid_t pid, shell_info_t *infos, tree_metadata_t *meta,
		redirectors_pipes_t pipes)
{
	int status = get_ps_status(pid, infos, meta);

	close(pipes.pfdi[1]);
	return (status);
}

int redirection_exec_binary(tnode_t *cmd_node, tree_metadata_t *meta,
		shell_info_t *infos, redirectors_pipes_t pipes);
{
	const char *binary_name = cmd_node.data->str;
	char *get_binary_access(binary_name, infos);
	char **env = list_to_arr(infos->env);

	if (!binary_path) {
		fprintf(stderr, "%s: Command not found.\n", binary_name);
		return (false);
	}
	if (!env) {
		return (-1);
	}
	child_pid = fork();
	if (!child_pid) {
		exec_process(env, binary_path, cmd_node.data->str, pipes);
		return (false);
	}
	free(env);
	return (get_ps_status(child_pid, infos, meta, pipes));
}
