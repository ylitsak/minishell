/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saylital <saylital@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 12:27:40 by saylital          #+#    #+#             */
/*   Updated: 2024/12/17 14:52:39 by saylital         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include "libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>


typedef struct s_minishell
{
	int		exit_code;
	char	**env_list;
} 	t_minishell;


//utils.c
void	free_args(char **commands);
void	free_env(t_minishell *shell);
void	print_error(char *message, t_minishell *shell, int status);
int		count_args(char **command);
//builtin
void	check_command(char **command, t_minishell *shell);
void	ft_echo(char **command, t_minishell *shell);
void	ft_pwd(char **command, t_minishell *shell);
void	ft_exit(char **command, t_minishell *shell);
void	ft_env(char **command, t_minishell *shell);
void	ft_cd(char **command, t_minishell *shell);
char 	**create_env(t_minishell *shell, char **envp);
int		update_pwd(t_minishell *shell, char *string, char *value);
int		env_list_size(char **envp)

#endif