/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saylital <saylital@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 10:24:22 by saylital          #+#    #+#             */
/*   Updated: 2024/12/02 13:51:52 by saylital         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_echo(char **command)
{
	int	i;

	i = 1;
	if (ft_strncmp(command[1], "-n", 2) == 0)
		i++;
	while (command[i])
	{
		printf("%s", command[i++]);
		if (command[i] != NULL)
			printf(" ");
	}
	if (ft_strncmp(command[1], "-n", 2) != 0)
		printf("\n");
	return ;
}