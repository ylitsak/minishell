/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saylital <saylital@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 14:39:40 by saylital          #+#    #+#             */
/*   Updated: 2024/12/17 13:43:16 by saylital         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_cd(char **command, t_minishell *shell)
{
	char	*oldpwd;
	char	*home;
	int		count;

	oldpwd = getcwd(NULL, 0);
	home =  getenv("HOME");
	count = count_args(command);
	if (!oldpwd)
	{
		free_args(command);
		free_env(shell);
		print_error("getcwd failed", shell, 1);
		exit(shell->exit_code);
	}
	if (count > 2)
	{
		print_error("minishell: cd: too many arguments", shell, 1);
		return ;
	}
	update_pwd(shell, "OLDPWD=", oldpwd);
	if (count == 1)
	{
		if (chdir(home) == -1)
			//need to free stuff and setup correct exit code if home not found
			perror("");
		return ;
	}
	else
	{
		if (chdir(command[1]) == -1)
		{
			perror("");
			//need to free stuff
			shell->exit_code = 1;
		}
		return ;
	}
}
