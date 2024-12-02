/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saylital <saylital@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 13:17:41 by saylital          #+#    #+#             */
/*   Updated: 2024/12/02 13:27:35 by saylital         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	check_command(char **input)
{
	if (ft_strncmp(input[0], "echo", 4) == 0)
		ft_echo(input);
	return ;
}