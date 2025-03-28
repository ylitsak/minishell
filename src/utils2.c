/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saylital <saylital@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 12:12:00 by saylital          #+#    #+#             */
/*   Updated: 2025/03/28 17:04:39 by saylital         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	check_arg_len(t_command *cmd)
{
	int	i;
	if (!cmd || !cmd->args)
		return (0);
	i = ft_strlen(cmd->args[0]);
	return (i);
}
