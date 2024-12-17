/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saylital <saylital@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 12:27:11 by saylital          #+#    #+#             */
/*   Updated: 2024/12/16 14:50:46 by saylital         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void parsing(char *input, t_minishell *shell)
{
	char **command;

	command = ft_split(input, ' ');
	if (!command)
	{
		free(input);
		ft_putendl_fd("Malloc failed", 2);
		exit(EXIT_FAILURE);
	}
	free(input);
	check_command(command, shell);
	free_args(command);
	return ;
}

void static	init_shell(t_minishell *shell, char **envp)
{
	shell->env_list = create_env(shell, envp);
	shell->exit_code = 0;
}

int	main(int argc, char *argv[], char *envp[])
{
	(void)argc;
	(void)argv;
	t_minishell shell;
	init_shell(&shell, envp);
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
		parsing(input, &shell);
	}
	rl_clear_history();
	free_env(&shell);
	return (shell.exit_code);
}
