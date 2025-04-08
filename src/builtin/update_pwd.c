/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_pwd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saylital <saylital@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 13:47:21 by saylital          #+#    #+#             */
/*   Updated: 2025/04/07 14:39:46 by saylital         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	update_pwd(t_ms *shell, char *string, char *value)
{
	int		i;
	int		len;
	char	*new_value;

	i = 0;
	new_value = ft_strjoin(string, value);
	free(value);
	value = NULL;
	if (!new_value)
		malloc_error(shell);
	len = ft_strlen(string);
	while (shell->env_list[i])
	{
		if (ft_strncmp(shell->env_list[i], string, len) == 0)
		{
			free(shell->env_list[i]);
			shell->env_list[i] = new_value;
			return (0);
		}
		i++;
	}
	free(new_value);
	new_value = NULL;
	return (0);
}

void	error_and_exit_code(t_ms *shell)
{
	ft_putstr_fd("minishell: cd: HOME not set", 2);
	shell->exit_code = 1;
}

void	if_count_is_1(t_ms *shell, char *oldpwd, char *home)
{
	if (shell->pipe_count == 0)
	{
		if (chdir(home) == -1)
			error_and_exit_code(shell);
		update_pwd(shell, "OLDPWD=", shell->prev_pwd);
		shell->prev_pwd = NULL;
		free(oldpwd);
		oldpwd = getcwd(NULL, 0);
		update_pwd(shell, "PWD=", oldpwd);
		if (home)
		{
			free(home);
			home = NULL;
		}
	}
	else
	{
		free(home);
		home = NULL;
		free(oldpwd);
		oldpwd = NULL;
	}
}

void	if_pipe_count(t_ms *shell, char **command, char *oldpwd)
{
	free(oldpwd);
	oldpwd = NULL;
	if (access(command[1], F_OK))
	{
		ft_putstr_fd("cd: no such file or directory: ", 2);
		ft_putendl_fd(command[1], 2);
	}
	shell->exit_code = 1;
}
