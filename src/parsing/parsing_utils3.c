/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smishos <smishos@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 20:09:10 by smishos           #+#    #+#             */
/*   Updated: 2025/04/06 15:38:02 by smishos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	handle_token_append(t_ms *shell, t_command *cmd, t_token *token)
{
	char	*expanded_value;

	cmd->command_input[cmd->command_input_index] = ft_strdup(token->value);
	if (!cmd->command_input[cmd->command_input_index])
		malloc_error(shell);
	token = token->next;
	if (token && token->type == TOKEN_ARGS)
	{
		expanded_value = handle_expansions(shell, token->value);
		if (!expanded_value)
			malloc_error(shell);
		cmd->command_input[cmd->command_input_index + 1] = \
			ft_strdup(expanded_value);
		if (!cmd->command_input[cmd->command_input_index + 1])
			malloc_error(shell);
		cmd->append_mode = 1;
		free(expanded_value);
	}
	cmd->command_input_index += 2;
}

int	syntax_error_and_return(t_ms *shell, t_token *token)
{
	ft_putstr_fd("minishell: syntax error near unexpected token `", 2);
	ft_putstr_fd(token->next->value, 2);
	ft_putstr_fd("'\n", 2);
	shell->exit_code = 2;
	shell->token_error = 1;
	return (1);
}

int	handle_token_heredoc(t_ms *shell, t_command *cmd, t_token *token)
{
	int	i;

	if (pipe_syntax_check(shell, token))
		return (1);
	if (token && token->next && (token->next->type == TOKEN_REDIR_IN || \
		token->next->type == TOKEN_REDIR_OUT))
		return (syntax_error_and_return(shell, token));
	cmd->command_input[cmd->command_input_index] = ft_strdup(token->value);
	if (!cmd->command_input[cmd->command_input_index])
		malloc_error(shell);
	token = token->next;
	start_sig_checkers_hd(&sig_handler_heredoc);
	if (token && token->type == TOKEN_ARGS)
		setup_delim(shell, cmd, token);
	i = 0;
	shell->heredoc_line_count++;
	allocate_heredoc_lines(shell, cmd);
	rl_event_hook = event;
	i = 0;
	i = heredoc_loop(shell, cmd, i);
	if (g_signal == SIGINT)
		return (1);
	null_hd_and_oneline(shell, cmd, i);
	return (0);
}

void	handle_token_redir_out(t_ms *shell, t_command *cmd, t_token *token)
{
	char	*expanded_value;

	cmd->command_input[cmd->command_input_index] = ft_strdup(token->value);
	if (!cmd->command_input[cmd->command_input_index])
		malloc_error(shell);
	token = token->next;
	if (token && token->type == TOKEN_ARGS)
	{
		expanded_value = handle_expansions(shell, token->value);
		if (!expanded_value)
			malloc_error(shell);
		cmd->command_input[cmd->command_input_index + 1] \
			= ft_strdup(expanded_value);
		if (!cmd->command_input[cmd->command_input_index + 1])
			malloc_error(shell);
		cmd->redir_out = 1;
		free(expanded_value);
	}
	cmd->command_input_index += 2;
}

void	add_argument(t_command *cmd, char *arg, t_ms *shell)
{
	int		i;
	char	**new_args;

	i = 0;
	if (cmd->args)
	{
		while (cmd->args[i] != NULL)
			i++;
	}
	new_args = ft_realloc(cmd->args, sizeof(char *) * \
	(i + 1), sizeof(char *) * (i + 2));
	if (!new_args)
		malloc_error(shell);
	cmd->args = new_args;
	cmd->args[i] = ft_strdup(arg);
	if (!cmd->args[i])
		malloc_error(shell);
	cmd->args[i + 1] = NULL;
	cmd->next = NULL;
}
