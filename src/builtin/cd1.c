/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd1.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saylital <saylital@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 17:17:58 by smishos           #+#    #+#             */
/*   Updated: 2025/04/07 14:21:30 by saylital         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*get_home_var(t_ms *shell)
{
	int	i;

	i = 0;
	while (shell->env_list[i])
	{
		if (ft_strncmp(shell->env_list[i], "HOME=", 5) == 0)
			return (ft_strdup(shell->env_list[i] + 5));
		i++;
	}
	ft_putstr_fd("minishell: cd: HOME not set\n", 2);
	shell->exit_code = 1;
	return (NULL);
}

void	prev_pwd_func(t_ms *shell, char *oldpwd)
{
	if (shell->prev_pwd)
		free(shell->prev_pwd);
	shell->prev_pwd = ft_strdup(oldpwd);
	if (!shell->prev_pwd)
		malloc_error(shell);
}

int	cd_has_null(char **command, t_ms *shell)
{
	if (command[1])
	{
		if (*command[1] == '\0')
		{
			shell->exit_code = 0;
			return (1);
		}
	}
	return (0);
}

void	too_many_args(t_ms *shell)
{
	ft_putstr_fd("minishell: cd: too many arguments\n", 2);
	shell->exit_code = 1;
}

void	ft_cd_no_arg(char **command, t_ms *shell)
{
	char	*home;
	char	*oldpwd;

	home = get_home_var(shell);
	if (!home)
		return ;
	oldpwd = getcwd(NULL, 0);
	if (!oldpwd)
		return (if_not_oldpwd(shell, command, home, oldpwd));
	prev_pwd_func(shell, oldpwd);
	if_count_is_1(shell, oldpwd, home);
}
