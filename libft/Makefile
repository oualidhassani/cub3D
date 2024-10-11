NAME = libft.a
SRCS = ft_atoi.c  ft_itoa.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strlen.c ft_strcmp.c ft_putstr_fd2.c ft_putchar_fd2.c ft_putnbr_fd2.c ft_printfx.c ft_printadres.c ft_printf.c ft_printfu.c ft_is_string_digit.c ft_strncmp.c ft_isdigit.c

OBJ = $(SRCS:.c=.o)

AR = ar rcs

CC = cc

CFLAGS = -Wall -Werror -Wextra

RM = rm -f

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(AR) $(NAME) $?


clean:
	$(RM) $(OBJ) $(NAME)

fclean: clean
	$(RM) $(NAME)

re: fclean all


.PHONY: all bonus clean fclean re