/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saylital <saylital@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 13:50:38 by saylital          #+#    #+#             */
/*   Updated: 2024/12/17 12:43:19 by saylital         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_pwd(char **command, t_minishell *shell)
{
	char	*pwd;

	if (command[1])
	{
		print_error("pwd: too many arguments", shell, 1);
		return ;		
	}
	pwd = getcwd(NULL, 0);
	if (!pwd)
	{
		free_args(command);
		free_env(shell);
		print_error("getcwd failed", shell, 1);
		exit(shell->exit_code);
	}
	printf("%s\n", pwd);
	free(pwd);
	shell->exit_code = 0;
	return ;
}
