/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saylital <saylital@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 13:17:41 by saylital          #+#    #+#             */
/*   Updated: 2024/12/02 14:35:05 by saylital         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	check_command(char **command)
{
	if (ft_strncmp(command[0], "echo", 4) == 0)
		ft_echo(command);
	else if (ft_strncmp(command[0], "pwd", 3) == 0)
		ft_pwd(command);
	else if (ft_strncmp(command[0], "exit", 4) == 0)
		ft_exit(command);
	return ;
}