/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_command4.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saylital <saylital@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 20:08:54 by smishos           #+#    #+#             */
/*   Updated: 2025/04/07 13:24:05 by saylital         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	execute_command(t_ms *shell, char **args)
{
	char	*path;

	if (!shell->exec)
	{
		path = find_executable_path(shell, args);
		if (!path)
		{
			cleanup(shell, 1);
			exit(127);
		}
		if (execve(path, args, shell->env_list) == -1)
		{
			if (g_signal == SIGINT)
				write(1, "\n", 1);
			ft_putstr_fd("minishell execve: ", 2);
			ft_putstr_fd(strerror(errno), 2);
			ft_putstr_fd("\n", 2);
			shell->exit_code = 126;
			if (path)
				free(path);
			cleanup(shell, 1);
			exit(shell->exit_code);
		}
	}
}

void	child_process(t_ms *shell, t_command *command, int *new_pipe)
{
	int		i;
	char	**args;

	if (default_signals() == 1)
		print_error("Error: default_signals failed", shell, 1, 1);
	start_sig_checkers(&sig_handler_child);
	if (shell->prev_pipe_in != -1)
	{
		dup2(shell->prev_pipe_in, STDIN_FILENO);
		close(shell->prev_pipe_in);
	}
	if (command->next)
	{
		close(new_pipe[0]);
		dup2(new_pipe[1], STDOUT_FILENO);
		close(new_pipe[1]);
	}
	i = -1;
	while (command->command_input[++i])
		execute_redir(shell, command, i);
	args = command->args;
	shell->exec = is_builtin(args, shell);
	execute_command(shell, args);
	cleanup(shell, 1);
	exit(shell->exit_code);
}

t_command	*parent_process(t_ms *shell, t_command *command, int *new_pipe)
{
	close_prew_pipe(shell);
	if (!command->next)
		shell->last_pid = command->pid;
	if (command->next)
	{
		close(new_pipe[1]);
		(shell->prev_pipe_in) = new_pipe[0];
	}
	command = command->next;
	return (command);
}

t_command	*check_for_exit(t_ms *shell, t_command *command)
{
	ft_exit(command, shell);
	command = command->next;
	return (command);
}
