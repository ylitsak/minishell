/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saylital <saylital@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 14:39:40 by saylital          #+#    #+#             */
/*   Updated: 2024/12/09 13:25:44 by saylital         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// void	ft_cd(char **command, t_minishell *shell)
// {
// 	char	*oldpwd;

// 	oldpwd = getcwd(NULL, 0);
// 	if (!oldpwd)
// 	{
// 		free_args(command);
// 		free_env(shell);
// 		ft_putendl_fd("getcwd failed", 2);
// 		exit(EXIT_FAILURE);
// 	}
// 	if (!command[1])
// 	{

// 	}
// }