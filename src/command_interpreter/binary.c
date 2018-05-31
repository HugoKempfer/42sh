/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** Execute binaries and redirect outputs to redirectors
*/

#include "redirections.h"
#include "built_in_exec.h"
#include "binary_exec.h"
#include "binary_tree.h"
#include "42sh.h"
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static void handle_builtin_ps(built_in_fptr *func, shell_info_t *infos,
		char **command, int pipes[3])
{
	if (pipes[IN] != -1) {
		if (dup2(pipes[IN], 0) == -1) {
			return;
		}
		close(pipes[IN]);
	}
	if (pipes[OUT] != -1) {
		if (dup2(pipes[OUT], 1) == -1) {
			return;
		}
		close(pipes[OUT]);
	}
	if (pipes[TO_CLOSE] != -1) {
		close(pipes[TO_CLOSE]);
	}
	exit(func(infos, command));
}

int redirection_exec_builtin(built_in_fptr *func, shell_info_t *infos,
		char **command, int pipes[3])
{
	pid_t child_pid = fork();

	if (!child_pid) {
		handle_builtin_ps(func, infos, command, pipes);
		return (false);
	}
	return (true);
}

static void exec_process(char **env, char *binary_path, char **command,
		int pipes[3])
{
	if (pipes[IN] != -1) {
		if (dup2(pipes[IN], 0) == -1) {
			return;
		}
		close(pipes[IN]);
	}
	if (pipes[OUT] != -1) {
		if (dup2(pipes[OUT], 1) == -1) {
			return;
		}
		close(pipes[OUT]);
	}
	if (pipes[TO_CLOSE] != -1) {
		close(pipes[TO_CLOSE]);
	}
	execve(binary_path, command, env);
}

static int manage_ps(pid_t pid, shell_info_t *infos, tree_metadata_t *meta,
		int pipes[3])
{
	int status = get_ps_status(pid, infos, meta);

	return (status);
}

int redirection_exec_binary(tnode_t *cmd_node, tree_metadata_t *meta,
		shell_info_t *infos, int pipes[3])
{
	char *binary_name = *(cmd_node->data.str);
	char *binary_path = get_binary_access(binary_name, infos);
	char **env = list_to_arr(infos->env);
	pid_t child_pid;

	if (!binary_path) {
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
