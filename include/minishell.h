/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saylital <saylital@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 20:07:41 by smishos           #+#    #+#             */
/*   Updated: 2025/03/28 12:12:51 by saylital         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include "../libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>

extern int	g_signal;

// Simplified token types
enum e_token_type
{
	TOKEN_ARGS,
	TOKEN_PIPE,
	TOKEN_REDIR_IN,
	TOKEN_HERE_DOC,
	TOKEN_REDIR_OUT,
	TOKEN_APPEND
};

typedef struct s_command
{
	char				**args;
	int					arg_count;
	struct s_command	*next;
	int					free_input_count;
	int					free_output_count;
	char				*heredoc_delimiter;
	char				**heredoc_lines;
	char				*heredoc_line;
	int					heredoc;
	int					redir_in;
	int					redir_out;
	int					append_mode;
	pid_t				pid;
	char				**command_input;
	int					command_input_index;
}	t_command;

typedef struct s_token
{
	char			*value;
	int				type;
	struct s_token	*next;
}	t_token;

typedef struct s_exp
{
	int		i;
	int		j;
	int		var_start;
	int		var_len;
	char	*result;
	int		closing_quote;
	char	quote_type;
	int		closing_brace;
	char	*var_name;
	char	*value;
}	t_exp;

typedef struct s_ms
{
	unsigned char	exit_code;
	char			**env_list;
	char			*input;
	int				child_count;
	int				pipe_count;
	t_token			*token;
	t_token			*next_start;
	t_command		*commands;
	t_exp			exp;
	int				i;
	char			*buffer;
	char			*new_buffer;
	int				buf_count;
	int				buf_i;
	int				type;
	int				equal_found;
	int				rd_in_count;
	int				rd_out_count;
	pid_t			last_pid;
	pid_t			wpid;
	int				status;
	int				heredoc_line_count;
	char			*prev_pwd;
	int				token_error;
	char			*pipe_rdl_tokens;
	int				exit_error_flag;
	int				exp_i;
	int				exp_name_len;
	char			*exp_temp_name;
	int				command_input_count;
	int				heredoc_exp;
	int				select_command_found;
	int				prev_pipe_in;
	int				exec;
}	t_ms;

// signals
int				check_signals(int signum, void (*handler_function)(int));
void			sig_handler_child(int signal);
void			sig_handler_sigint(int signal);
void			sig_handler_heredoc(int signal);
int				default_signals(void);
int				init_signals(void);
void			start_sig_checkers(void *handler_func);
//utils.c
void			free_args(char **commands);
void			free_env(t_ms *shell);
void			print_error(char *message, t_ms *shell, \
					unsigned char status, int clean_shell);
int				count_args(char **command);
void			malloc_error(t_ms *shell);
char			*free_and_nullify(char *str_ptr);
int				validate_str(char *str, char *acc_values);
char			*count_for_malloc(char *str);
int				event(void);
void			ft_putstr_eq(char *str);
int				check_arg_len(t_command *cmd);
//builtin
void			ft_echo(char **command, t_ms *shell);
void			ft_pwd(t_ms *shell);
void			ft_exit(t_command *command, t_ms *shell);
void			ft_env(char **command, t_ms *shell);
void			ft_cd(char **command, t_ms *shell);
char			*get_home_var(t_ms *shell);
void			if_count_is_1(t_ms *shell, char *oldpwd, char *home);
void			execute_cd(t_ms *shell, char **command, char *oldpwd);
void			error_and_exit_code(t_ms *shell);
void			if_pipe_count(t_ms *shell, char **command, char *oldpwd);
void			create_env(t_ms *shell, char **envp);
int				update_pwd(t_ms *shell, char *string, char *value);
int				env_list_size(char **envp);
void			ft_export(char **command, t_ms *shell);
void			print_variables(char	**copy_list, int i);
void			print_sorted_env(t_ms *shell);
void			export_error(t_ms *shell, char *arg);
void			if_value_not_empty(t_ms *shell, char *key, char *value, int i);
void			if_equal_found(t_ms *shell, char *key, int i);
int				sift_through_env(t_ms *shell, char *key, char *value, int i);
void			realloc_env_list(t_ms *shell);
void			equal_sign_no_value(t_ms *shell, char *key, int i);
void			value_or_no_value(t_ms *shell, char *key, char *value, int i);
void			set_env_variable(t_ms *shell, char *key, char *value, \
					char *equal_sign);
void			quicksort(char **arr, int low, int high);
void			ft_unset(char **command, t_ms *shell);
// execution
void			check_command(t_ms *shell, t_command *command);
int				is_parent_builtin(char **command, t_ms *shell);
int				is_builtin(char **command, t_ms *shell);
void			fork_error(int *new_pipe);
char			*find_path(char *cmd, char **envp);
int				is_dir(char *str);
char			*find_directory(char **dir, char *splitted_args);
void			find_exec_path_error(t_ms *shell, t_command *command, \
					char *message, int exit_code);
char			*access_check(t_ms *shell, t_command *command);
char			*find_executable_path(t_ms *shell, t_command *command);
void			error_free_clean_exit(t_ms *shell, char *message);
void			hir_hd_child_process(t_ms *shell, t_command *command, \
					int *pipefd);
void			handle_input_redirection(t_ms *shell, t_command *command, \
					char *symbol, char *file);
void			handle_output_redirection(t_ms *shell, char *symbol, \
					char *file);
void			wait_for_kids(t_ms *shell);
void			execute_redir(t_ms *shell, t_command *command, int i);
void			execute_command(t_ms *shell, t_command *command);
void			child_process(t_ms *shell, t_command *command, int *new_pipe);
t_command		*parent_process(t_ms *shell, t_command *command, int *new_pipe);
t_command		*check_for_dots(t_command *command);
t_command		*check_for_exit(t_ms *shell, t_command *command, int *new_pipe);
t_command		*checking_for_select_commands(t_ms *shell, t_command *command, \
					int *new_pipe);
void			parent_wait(t_ms *shell, t_command *command, int *pipefd);
void			pipe_failure(t_ms *shell);
// parser
void			parse_tokens(t_ms *shell);
char			*parse_quotes(char *str);
void			add_argument(t_command *cmd, char *arg);
char			*handle_expansions(t_ms *shell, const char *str);
void			handle_token_args(t_ms *shell, t_command *cmd, t_token *token);
t_command		*new_cmd_struct(t_ms *shell);
void			handle_token_redir_in(t_ms *shell, \
				t_command *cmd, t_token *token);
int				handle_token_heredoc(t_ms *shell, \
				t_command *cmd, t_token *token);
int				event(void);
void			handle_token_redir_out(t_ms *shell, \
				t_command *cmd, t_token *token);
void			handle_token_append(t_ms *shell, \
				t_command *cmd, t_token *token);
char			*handle_expansions_quotes(t_ms *shell, \
				const char *str);
int				find_closing_quote(t_ms *shell, \
				const char *str, char quote_type, int start);
int				find_closing_brace(const char *str, \
				int start);
void			expand_env_var(t_ms *shell, \
				int with_braces);
int				handle_expansions_dollar_sign(t_ms *shell, const char *str);
int				handle_expansions_no_braces(t_ms *shell, const char *str);
int				handle_expansions_if_braces(t_ms *shell, const char *str);
void			make_heredoc_one_line(t_ms *shell, t_command *cmd);
void			setup_delim(t_ms *shell, t_command *cmd, t_token *token);
void			allocate_heredoc_lines(t_ms *shell, t_command *cmd);
int				heredoc_loop(t_ms *shell, t_command *cmd, int i);
char			*qmark_check(t_ms *shell, int with_braces);
void			get_var_name_len(t_ms *shell, int with_braces);
void			get_var_value(t_ms *shell);
void			count_cmd_args(t_ms *shell, t_token *token);
void			check_for_append_lm(t_ms *shell);
void			write_token_args_lm(t_ms *shell);
void			checking_pipe_lm(t_ms *shell);
void			checking_rd_in_lm(t_ms *shell);
void			checking_rd_out_lm(t_ms *shell);
void			if_is_operator_lm(t_ms *shell);
int				is_operator_true_lm(t_ms *shell);
int				lead_pipe_check_lm(t_ms *shell, int lead_pipe);
void			free_shell_buffer(t_ms *shell);
void			tokenize_input_lm(t_ms *shell);
int				pipe_syntax_check(t_ms *shell, t_token *token);
void			pipe_no_next_token(t_ms *shell);
t_command		*new_command(t_ms *shell, t_command *cmd, t_token *token);
int				setup_command_input_count(t_ms *shell, t_command *cmd, \
					t_token *token);
void			realloc_and_write(t_ms *shell, const char *str, int inc_i, \
					int write);
void			var_len_not_zero(t_ms *shell, const char *str);
void			null_hd_and_oneline(t_ms *shell, t_command *cmd, int i);
int				print_ret(t_ms *shell, char *message);
// tokens folder
void			tokenize_input(t_ms *shell);
int				is_operator(char c);
void			write_token_args(t_ms *shell);
void			if_is_operator(t_ms *shell);
void			create_token(t_ms *shell);
void			add_token(t_ms *shell, t_token *new_token);
void			realloc_buffer(t_ms *shell);
void			if_quotes(t_ms *shell);
int				lead_pipe_check(t_ms *shell, int lead_pipe);
// file helpers
void			safe_dup2(int fd, int fd2);
void			read_file(t_ms *shell, char *file);
void			write_file(t_ms *shell, char *file);
void			append_file(t_ms *shell, char *file);
// errors and cleanup
void			cleanup(t_ms *shell, int clean_shell);
void			free_commands(t_command *commands);
void			free_tokens(t_ms *shell);
#endif