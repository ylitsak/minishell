/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saylital <saylital@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 12:12:00 by saylital          #+#    #+#             */
/*   Updated: 2025/03/28 12:17:34 by saylital         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	check_arg_len(t_command *cmd)
{
	int	i;

	i = ft_strlen(cmd->args[0]);
	return (i);
}
