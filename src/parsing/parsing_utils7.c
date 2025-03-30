/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils7.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saylital <saylital@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 20:09:21 by smishos           #+#    #+#             */
/*   Updated: 2025/03/30 18:17:45 by saylital         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	tokenize_input_lm(t_ms *shell)
{
	int	lead_pipe;

	lead_pipe = 1;
	shell->i = 0;
	shell->buf_count = 1;
	shell->buffer = NULL;
	while (shell->pipe_rdl_tokens[shell->i])
	{
		while (shell->pipe_rdl_tokens[shell->i] && \
			ft_isspace(shell->pipe_rdl_tokens[shell->i]))
			shell->i++;
		if (lead_pipe_check_lm(shell, lead_pipe))
			return ;
		if (!shell->pipe_rdl_tokens[shell->i])
			break ;
		lead_pipe = 0;
		if (is_operator_true_lm(shell))
			continue ;
		write_token_args_lm(shell);
		shell->buf_count = 1;
	}
	if (shell->buffer)
		free_shell_buffer(shell);
}

int	pipe_syntax_check(t_ms *shell, t_token *token)
{
	int	result;

	if (token->next->type == TOKEN_APPEND)
		result = print_ret(shell, \
		"minishell: syntax error near unexpected token `>>'");
	else if (token->next->type == TOKEN_HERE_DOC)
		result = print_ret(shell, \
		"minishell: syntax error near unexpected token `<<'");
	else if (token->next->type == TOKEN_REDIR_OUT)
		result = print_ret(shell, \
		"minishell: syntax error near unexpected token `>'");
	else if (token->next->type == TOKEN_REDIR_IN)
		result = print_ret(shell, \
		"minishell: syntax error near unexpected token `<'");
	else if (token->next->type == TOKEN_PIPE)
		result = print_ret(shell, \
		"minishell: syntax error near unexpected token `|'");
	else
		result = 0;
	return (result);
}

void	pipe_no_next_token(t_ms *shell)
{
	shell->pipe_rdl_tokens = readline("> ");
	if (!shell->pipe_rdl_tokens)
	{
		cleanup(shell, 1);
		exit(2);
	}
	add_history(shell->pipe_rdl_tokens);
	tokenize_input_lm(shell);
	free(shell->pipe_rdl_tokens);
	shell->pipe_rdl_tokens = NULL;
}

t_command	*new_command(t_ms *shell, t_command *cmd, t_token *token)
{
	t_command	*new_cmd;

	if (cmd && cmd->command_input && cmd->command_input_index >= 0)
		cmd->command_input[cmd->command_input_index] = NULL;
	new_cmd = new_cmd_struct(shell);
	cmd->next = new_cmd;
	cmd->next->command_input = cmd->command_input;
	cmd = new_cmd;
	cmd->command_input_index = 0;
	cmd->next = NULL;
	count_cmd_args(shell, shell->next_start);
	cmd->command_input = (char **) malloc(sizeof(char *) * \
		(shell->command_input_count));
	if (!cmd->command_input)
		malloc_error(shell);
	while (cmd->command_input_index < shell->command_input_count)
	{
		cmd->command_input[cmd->command_input_index] = NULL;
		cmd->command_input_index++;
	}
	cmd->command_input_index = 0;
	if (!token->next)
		pipe_no_next_token(shell);
	return (cmd);
}

int	setup_command_input_count(t_ms *shell, t_command *cmd, t_token *token)
{
	count_cmd_args(shell, token);
	if (shell->command_input_count > 0)
	{
		cmd->command_input = (char **) malloc(sizeof(char *) * \
			(shell->command_input_count + 1));
		if (!cmd->command_input)
			malloc_error(shell);
	}
	cmd->command_input_index = 0;
	while (cmd->command_input_index < shell->command_input_count)
	{
		cmd->command_input[cmd->command_input_index] = NULL;
		cmd->command_input_index++;
	}
	return (shell->command_input_count);
}
