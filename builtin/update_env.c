/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saylital <saylital@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 13:47:21 by saylital          #+#    #+#             */
/*   Updated: 2024/12/10 11:33:33 by saylital         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	update_env(t_minishell *shell, char *string, char *value)
{
	int		i;
	int		len;
	char	*new_value;

	i = 0;
	new_value = ft_strjoin(string, value);
	if (!new_value)
	{
		ft_putendl_fd("Malloc failed update_env", 2);
		return (-1);
	}
	len = ft_strlen(string);
	printf("%s\n", string);
	while (shell->env_list[i])
	{
		if (ft_strncmp(shell->env_list[i], string, len) == 0)
		{
			printf("we should get here!!!!!\n");
			free(shell->env_list[i]);
			shell->env_list[i] = new_value;
			return (0);
		}
		i++;
	}
	return (0);
}
