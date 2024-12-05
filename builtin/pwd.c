/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saylital <saylital@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 13:50:38 by saylital          #+#    #+#             */
/*   Updated: 2024/12/05 14:26:16 by saylital         ###   ########.fr       */
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
		ft_putendl_fd("getcwd failed", 2);
		exit(EXIT_FAILURE);
	}
	printf("%s\n", pwd);
	free(pwd);
	return ;
}
