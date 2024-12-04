/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saylital <saylital@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 14:33:02 by saylital          #+#    #+#             */
/*   Updated: 2024/12/04 11:41:38 by saylital         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	check_numeric(char **command, t_minishell *shell)
{
	int	i;

	i = 0;
	if (command[1][i] == '#')
		return ;
	while(command[1][i])
	{
		if (ft_isalpha(command[1][i]) == 1)
		{
			print_error("exit: numeric argument required", shell, 2);
			exit(shell->exit_code);
		}
		i++;	
	}
}

void	ft_exit(char **command, t_minishell *shell)
{
	check_numeric(command, shell);
	if (command[2])
	{
		print_error("exit: too many arguments", shell, 1);
		return ;
	}
	// need to check # edge case since its apparently treated as a comment and ignores eveyrthing after that
	return ;
}
