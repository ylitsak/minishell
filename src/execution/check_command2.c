/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_command2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smishos <smishos@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 20:08:48 by smishos           #+#    #+#             */
/*   Updated: 2025/04/06 16:34:45 by smishos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*null_split_args(t_ms *shell, char *splitted_args)
{
	if (!(*splitted_args))
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(splitted_args, 2);
		ft_putstr_fd(": command not found\n", 2);
		shell->exit_code = 127;
		return (NULL);
	}
	return (splitted_args);
}

char	*find_directory(t_ms *shell, char **dir, char *splitted_args)
{
	int		i;
	char	*executable_path;
	char	*slash;

	i = -1;
	while (dir[++i] != NULL)
	{
		if (!null_split_args(shell, splitted_args))
			return (NULL);
		slash = ft_strjoin(dir[i], "/");
		if (!slash)
			malloc_error(shell);
		executable_path = ft_strjoin(slash, splitted_args);
		free(slash);
		if (!executable_path)
			malloc_error(shell);
		if (access(executable_path, F_OK) == 0)
		{
			if (access(executable_path, X_OK) == 0)
				return (executable_path);
			perm_den_exit(shell, executable_path);
		}
		free(executable_path);
	}
	return (cmd_not_found(splitted_args));
}

void	find_exec_path_error(t_ms *shell, char **args, \
							char *message, int exit_code)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(args[0], 2);
	ft_putstr_fd(message, 2);
	if (exit_code)
	{
		cleanup(shell, 1);
		exit(exit_code);
	}
}

char	*access_check(t_ms *shell, char **args)
{
	if (access(args[0], F_OK) == 0)
	{
		if (access(args[0], X_OK) == 0)
		{
			if (!is_dir(args[0]))
				return (ft_strdup(args[0]));
			find_exec_path_error(shell, args, ": Is a directory\n", 126);
		}
		find_exec_path_error(shell, args, ": Permission denied\n", 126);
	}
	find_exec_path_error(shell, args, ": No such file or directory\n", 0);
	return (NULL);
}

char	*find_executable_path(t_ms *shell, char **args)
{
	char	*get_path;
	char	**path_directory;
	char	*found_path;
	char	**envp;

	if (ft_strchr(args[0], '/'))
		return (access_check(shell, args));
	envp = shell->env_list;
	get_path = find_path(args[0], envp);
	if (!get_path)
		return (NULL);
	path_directory = ft_split(get_path, ':');
	if (!path_directory)
		return (NULL);
	found_path = find_directory(shell, path_directory, args[0]);
	free_split(path_directory);
	return (found_path);
}
