/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saylital <saylital@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 10:24:22 by saylital          #+#    #+#             */
/*   Updated: 2024/12/02 13:35:19 by saylital         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_echo(char **input)
{
	int	i;

	i = 1;
	if (ft_strncmp(input[1], "-n", 2) == 0)
		i++;
	while (input[i])
	{
		printf("%s", input[i++]);
		if (input[i] != NULL)
			printf(" ");
	}
	if (ft_strncmp(input[1], "-n", 2) != 0)
		printf("\n");
	return ;
}