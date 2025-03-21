/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smishos <smishos@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 20:08:22 by smishos           #+#    #+#             */
/*   Updated: 2025/03/20 17:52:44 by smishos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	realloc_env_list(t_ms *shell)
{
	shell->env_list = ft_realloc(shell->env_list, \
	sizeof(char *) * env_list_size(shell->env_list), \
	sizeof(char *) * (env_list_size(shell->env_list) + 2));
	if (!shell->env_list)
		malloc_error(shell);
}

void	equal_sign_no_value(t_ms *shell, char *key, int i)
{
	char	*temp;

	temp = ft_strjoin(key, "\"\"");
	shell->env_list[i] = ft_strdup(temp);
	free(temp);
}

void	value_or_no_value(t_ms *shell, char *key, char *value, int i)
{
	if (ft_strchr(key, '=') && !value)
		equal_sign_no_value(shell, key, i);
	else
		shell->env_list[i] = ft_strdup(key);
	i++;
	shell->env_list[i] = NULL;
}

void	set_env_variable(t_ms *shell, char *key, char *value, char *equal_sign)
{
	int		i;

	i = 0;
	if (!ft_isalpha(key[i]) && key[i] != '_')
		return (export_error(shell, key));
	i++;
	while (key[i])
	{
		if (!ft_isalnum(key[i]) && key[i] != '_')
			return (export_error(shell, key));
		i++;
	}
	while (shell->env_list[i])
	{
		if (sift_through_env(shell, key, value, i))
			return ;
		i++;
	}
	if (shell->equal_found)
		equal_sign[0] = '=';
	realloc_env_list(shell);
	value_or_no_value(shell, key, value, i);
}

void	print_variables(char	**copy_list, int i)
{
	if (ft_strchr(copy_list[i], '='))
		ft_putstr_eq(copy_list[i]);
	else
		ft_putstr_fd(copy_list[i], 1);
	ft_putstr_fd("\n", 1);
}
