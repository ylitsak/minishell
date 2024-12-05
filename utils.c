/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saylital <saylital@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 13:39:22 by saylital          #+#    #+#             */
/*   Updated: 2024/12/05 14:03:08 by saylital         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_args_and_env(char **commands, t_minishell *shell)
{
	int	i;

	i = 0;
	if (commands)
	{
		while(commands[i])
		{
			free(commands[i]);
			i++;
		}
	}
	free(commands);
	i = 0;
	if (shell->env_list)
	{
		while(shell->env_list[i])
		{
			free(shell->env_list[i]);
			i++;
		}
	}
	free(shell->env_list);
}

void	print_error(char *message, t_minishell *shell, int status)
{
	ft_putendl_fd(message, 2);
	shell->exit_code = status;
}
