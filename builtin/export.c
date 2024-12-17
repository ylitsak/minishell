/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saylital <saylital@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 12:43:38 by saylital          #+#    #+#             */
/*   Updated: 2024/12/17 15:18:39 by saylital         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	env_alphabetic(t_minishell *shell)
{
	int		i;
	int		size;
	char	**copy_list;

	i = 0;
	size = env_list_size(shell->env_list);
	copy_list = malloc((size + 1) * sizeof(char *));
	//handle malloc fail and free stuff
	while (shell->env_list[i])
	{
		copy_list[i] = shell->env_list[i];
		i++;
	}
	copy_list[i] = NULL;
	sort_aplhabetically()
	
}

void	ft_export(char **command, t_minishell *shell)
{
	int	i;

	i = 0;
	if (!command[1])
	{
		//this probably need to be custom function and printed alphabetically
		ft_env(command, shell);
		return ;
	}


}