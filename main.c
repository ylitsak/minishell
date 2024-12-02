/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saylital <saylital@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 12:27:11 by saylital          #+#    #+#             */
/*   Updated: 2024/12/02 13:42:53 by saylital         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void parsing(char *input)
{
	char **command;

	command = ft_split(input, ' ');
	if (!command)
	{
		free(input);
		ft_putendl_fd("Malloc failed", 2);
	}
	free(input);
	check_command(command);
	free_args(command);
	return ;
}

int	main(int argc, char *argv[], char *envp[])
{
	(void)argc;
	(void)argv;
	(void)envp;
	char	*input;
	while (1)
	{
		input = readline("minishell> ");
		if (!input)
		{
			printf("exit\n");
			break ;
		}
		if (*input)
		{
			add_history(input);
		}
		parsing(input);
	}
	return (0);
}