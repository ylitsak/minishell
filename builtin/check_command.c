/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saylital <saylital@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 13:17:41 by saylital          #+#    #+#             */
/*   Updated: 2024/12/05 14:42:40 by saylital         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	check_command(char **command, t_minishell *shell)
{
	if (ft_strncmp(command[0], "echo", 4) == 0)
		ft_echo(command, shell);
	else if (ft_strncmp(command[0], "pwd", 3) == 0)
		ft_pwd(command, shell);
	else if (ft_strncmp(command[0], "exit", 4) == 0)
		ft_exit(command, shell);
	else if (ft_strncmp(command[0], "env", 3) == 0)
		ft_env(command, shell);
	else if (ft_strncmp(command[0], "cd", 2) == 0)
		ft_cd(command, shell);
	return ;
}