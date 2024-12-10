/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saylital <saylital@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 10:34:14 by saylital          #+#    #+#             */
/*   Updated: 2024/12/10 12:10:39 by saylital         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	env_list_size(char **envp)
{
	int 	i;

	i = 0;
	while (envp[i])
		i++;
	return (i);
}
static char	**copy_env(t_minishell *shell, char **env_list, char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		env_list[i] = ft_strdup(envp[i]);
		if (env_list[i] == NULL)
		{
			while (--i >= 0)
				free(env_list[i]);
			free(env_list);
			print_error("Malloc failed copy_env", shell, 1);
			exit(shell->exit_code);
		}
		i++;
	}
	env_list[i] = NULL;
	return (env_list);
}

char **create_env(t_minishell *shell, char **envp)
{
	int		env_size;
	char	**env_list;

	env_size = env_list_size(envp);
	env_list = malloc((env_size + 1) * sizeof(char *));
	if (!env_list)
	{
		print_error("Malloc failed create_env", shell, 1);
		exit(shell->exit_code);
	}
	env_list = copy_env(shell, env_list, envp);
	return (env_list);
}

void	ft_env(char **command, t_minishell *shell)
{
	int	i;

	i = 0;
	if (command[1])
	{
		ft_putstr_fd("env: ’", 2);
		ft_putstr_fd(command[1], 2);
		ft_putendl_fd("’: No such file or directory", 2);
		shell->exit_code = 127;
		return ;
	}
	while (shell->env_list[i] != NULL)
	{
		printf("%s\n", shell->env_list[i]);
		i++;
	}
	return ;
}
