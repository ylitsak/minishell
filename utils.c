/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saylital <saylital@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 13:39:22 by saylital          #+#    #+#             */
/*   Updated: 2024/12/02 13:41:29 by saylital         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_args(char **commands)
{
	int	i;

	i = 0;
	while(commands[i])
	{
		free(commands[i]);
		i++;
	}
	free(commands);
}