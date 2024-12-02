NAME = minishell
CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDE = -I ./libft
SRCS = main.c utils.c \
		builtin/echo.c builtin/check_command.c
OBJ_DIR = objects
OBJS = $(addprefix $(OBJ_DIR)/,  $(SRCS:.c=.o))
LIBFT = ./libft/libft.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) -o $(NAME) $(OBJS) $(LIBFT) -lreadline

$(LIBFT):
	@$(MAKE) -C ./libft

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)
	@$(MAKE) clean -C ./libft

fclean: clean
	rm -f $(NAME) $(LIBFT)

re: fclean all

.PHONY: clean fclean re all