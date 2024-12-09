/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saylital <saylital@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 13:47:21 by saylital          #+#    #+#             */
/*   Updated: 2024/12/09 14:30:04 by saylital         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

//**env_list probably need to pass as t_minishell *shell and then update it directly to the structure */
int	update_env(char **env_list, char *string, char *value)
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
	len = new_value;
	while (env_list[i])
	{
		if (ft_strncmp(env_list[i], string, len) == 0)
		{
			free(env_list[i]);
			env_list[i] = new_value;
			return (0);
		}
		i++;
	}
}
