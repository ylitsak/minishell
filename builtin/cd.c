/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saylital <saylital@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 14:39:40 by saylital          #+#    #+#             */
/*   Updated: 2024/12/10 12:21:10 by saylital         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_cd(char **command, t_minishell *shell)
{
	char	*oldpwd;
	int		count;

	oldpwd = getcwd(NULL, 0);
	count = count_args(command);
	if (!oldpwd)
	{
		free_args(command);
		free_env(shell);
		ft_putendl_fd("getcwd failed", 2);
		exit(EXIT_FAILURE);
	}
	if (count > 2)
	{
		ft_putendl_fd("minishell: cd: too many arguments", 2);
		shell->exit_code = 1;
		return ;
	}
	if (count == 1)
	{
		update_env(shell, "OLDPWD=", oldpwd);
		if (chdir(command[0]) == -1)
			perror("");
		return ;
	}
	else
	{
		update_env(shell, "OLDPWD=", oldpwd);
		if (chdir(command[1]) == -1)
		{
			perror("");
			shell->exit_code = 1;
		}
		return ;
	}
}
