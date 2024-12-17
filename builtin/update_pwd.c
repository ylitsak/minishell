/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_pwd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saylital <saylital@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 13:47:21 by saylital          #+#    #+#             */
/*   Updated: 2024/12/17 13:41:41 by saylital         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"


int	update_pwd(t_minishell *shell, char *string, char *value)
{
	int		i;
	int		len;
	char	*new_value;

	i = 0;
	new_value = ft_strjoin(string, value);
	free(value);
	if (!new_value)
	{
		print_error("Malloc failed update_env", shell, 1);
		//need to free args but ft_split command is not used, when parsing is done properly
		free_env(shell);
		exit(shell->exit_code);
	}
	len = ft_strlen(string);
	while (shell->env_list[i])
	{
		if (ft_strncmp(shell->env_list[i], string, len) == 0)
		{
			free(shell->env_list[i]);
			shell->env_list[i] = new_value;
			return (0);
		}
		i++;
	}
	return (0);
}
