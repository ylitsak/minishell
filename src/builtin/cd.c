/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saylital <saylital@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 14:39:40 by saylital          #+#    #+#             */
/*   Updated: 2025/03/28 12:52:11 by saylital         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	cd_to_arg(char **command, t_ms *shell)
{
	if (chdir(command[1]) == -1)
	{
		ft_putstr_fd("minishell: cd: ", 2);
		ft_putstr_fd(command[1], 2);
		ft_putstr_fd(": No such file or directory\n", 2);
		shell->exit_code = 1;
		return (1);
	}
	return (0);
}

void	if_not_oldpwd(t_ms *shell, char **command, char *home, char *oldpwd)
{
	if (ft_strncmp(command[1], "..", 2) == 0)
	{
		ft_putstr_fd("cd: error retrieving current directory: ", 2);
		ft_putstr_fd("getcwd: cannot access parent directories: ", 2);
		ft_putstr_fd("No such file or directory\n", 2);
		shell->exit_code = 0;
		free(home);
		return ;
	}
	if (chdir(home) == -1)
		error_and_exit_code(shell);
	free(home);
	oldpwd = getcwd(NULL, 0);
	update_pwd(shell, "OLDPWD=", shell->prev_pwd);
	update_pwd(shell, "PWD=", oldpwd);
}

void	too_many_args(t_ms *shell, char *oldpwd)
{
	ft_putstr_fd("minishell: cd: too many arguments\n", 2);
	free(oldpwd);
	shell->exit_code = 1;
}

void	execute_cd(t_ms *shell, char **command, char *oldpwd)
{
	char	*temp;

	update_pwd(shell, "OLDPWD=", oldpwd);
	if (cd_to_arg(command, shell) == 0 && ft_strncmp(command[1], "..", 2) != 0)
	{
		temp = ft_strjoin(shell->prev_pwd, "/");
		free(shell->prev_pwd);
		shell->prev_pwd = ft_strjoin(temp, command[1]);
		free(temp);
	}
}

void	ft_cd(char **command, t_ms *shell)
{
	char	*oldpwd;
	char	*home;
	int		count;

	home = get_home_var(shell);
	if (!home)
		return ;
	count = count_args(command);
	oldpwd = getcwd(NULL, 0);
	if (!oldpwd)
		return (if_not_oldpwd(shell, command, home, oldpwd));
	if (shell->prev_pwd)
		free(shell->prev_pwd);
	shell->prev_pwd = ft_strdup(oldpwd);
	if (count == 1)
		return (if_count_is_1(shell, oldpwd, home));
	free(home);
	if (count > 2)
		return (too_many_args(shell, oldpwd));
	if (shell->child_count > 0)
		return (if_pipe_count(shell, command, oldpwd));
	else
		execute_cd(shell, command, oldpwd);
	oldpwd = getcwd(NULL, 0);
	update_pwd(shell, "PWD=", oldpwd);
}
