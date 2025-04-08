/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smishos <smishos@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 20:09:02 by smishos           #+#    #+#             */
/*   Updated: 2025/04/06 17:02:22 by smishos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*parse_quotes(char *str)
{
	int		i;
	int		j;
	char	*parsed;

	if (!str)
		return (NULL);
	parsed = count_for_malloc(str);
	if (!parsed)
		return (NULL);
	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] != 34 && str[i] != 39)
			parsed[j++] = str[i];
		i++;
	}
	parsed[j] = '\0';
	return (parsed);
}

void	setup_delim(t_ms *shell, t_command *cmd, t_token *token)
{
	char	*stripped;

	shell->heredoc_exp = 1;
	if (token->value[0] == '\"' || token->value[0] == '\'')
		shell->heredoc_exp = 0;
	stripped = parse_quotes(token->value);
	if (!stripped)
		malloc_error(shell);
	cmd->heredoc_delimiter = ft_strdup(stripped);
	free(stripped);
	if (!cmd->heredoc_delimiter)
		malloc_error(shell);
}

void	allocate_heredoc_lines(t_ms *shell, t_command *cmd)
{
	cmd->heredoc_lines = (char **) malloc(sizeof(char *) * 2);
	if (!cmd->heredoc_lines)
		malloc_error(shell);
	cmd->heredoc_lines[0] = NULL;
}

int	heredoc_lines_err(t_ms *shell, t_command *cmd, int i)
{
	if (!cmd->heredoc_lines[i])
	{
		ft_putstr_fd("minishell: warning: here-document at line ", 2);
		ft_putnbr_fd(shell->heredoc_line_count, 2);
		ft_putstr_fd(" delimited by end-of-file (wanted `", 2);
		ft_putstr_fd(cmd->heredoc_delimiter, 2);
		ft_putstr_fd("')", 2);
		ft_putstr_fd("\n", 2);
		free(cmd->heredoc_delimiter);
		cmd->heredoc_delimiter = NULL;
		return (1);
	}
	return (0);
}

int	heredoc_loop(t_ms *shell, t_command *cmd, int i)
{
	while (1)
	{
		cmd->heredoc_lines = ft_realloc(cmd->heredoc_lines, \
				sizeof(char *) * i, sizeof(char *) * (i + 1));
		if (!cmd->heredoc_lines)
			malloc_error(shell);
		cmd->heredoc_lines[i] = readline("> ");
		if (g_signal == SIGINT)
			break ;
		if (heredoc_lines_err(shell, cmd, i))
			break ;
		if (ft_strncmp(cmd->heredoc_lines[i], cmd->heredoc_delimiter, \
			ft_strlen(cmd->heredoc_lines[i])) == 0)
		{
			free(cmd->heredoc_delimiter);
			cmd->heredoc_delimiter = NULL;
			break ;
		}
		if (cmd->heredoc_lines[i][0] == '$' && shell->heredoc_exp)
			cmd->heredoc_lines[i] = \
				handle_expansions(shell, cmd->heredoc_lines[i]);
		i++;
	}
	return (i);
}
