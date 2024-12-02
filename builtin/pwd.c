/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saylital <saylital@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 13:50:38 by saylital          #+#    #+#             */
/*   Updated: 2024/12/02 14:25:28 by saylital         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_pwd(char **command)
{
	char	*pwd;

	if (command[1])
	{
		ft_putendl_fd("too many arguments", 2);
		return ;		
	}
	pwd = getcwd(NULL, 0);
	if (!pwd)
	{
		free_args(command);
		ft_putendl_fd("getcwd failed", 2);
		exit(EXIT_FAILURE);
	}
	printf("%s\n", pwd);
	free(pwd);
	return ;
}
