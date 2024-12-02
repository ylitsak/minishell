NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS = ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_memcpy.c \
ft_memset.c ft_strlen.c ft_strnstr.c ft_tolower.c ft_toupper.c ft_strncmp.c ft_strlcpy.c ft_strchr.c \
ft_memmove.c ft_memchr.c ft_memcmp.c ft_atoi.c ft_strlcat.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c \
ft_strrchr.c ft_strtrim.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
ft_putnbr_fd.c ft_split.c ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstadd_back_bonus.c \
ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c
FT_PRINTF = ft_printf/ft_printf.c ft_printf/ft_print_hexadeci.c ft_printf/ft_print_num.c \
ft_printf/ft_print_pointer.c ft_printf/ft_print_str.c ft_printf/ft_print_unsigned_num.c ft_printf/ft_putchar.c
GET_NEXT_LINE = get_next_line/get_next_line.c get_next_line/get_next_line_utils.c
SRCS += $(GET_NEXT_LINE) $(FT_PRINTF)
OBJS = ${SRCS:.c=.o}

all: ${NAME}

${NAME}: ${OBJS}
	ar rcs ${NAME} ${OBJS}

%.o: %.c
	${CC} ${CFLAGS} -I./ -c $< -o $@

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: clean fclean re all