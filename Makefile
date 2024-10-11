NAME = cub3D

CC = cc

CFLAGS = -Wall -Wextra -Werror -ggdb3 -fsanitize=address

SRCS = main.c parsing.c parsing2.c get_next_line.c get_next_line_utils.c 

OBJ = $(SRCS:.c=.o)

AR = ar rcs

RM = rm -rf

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)
	make clean -C $(LIBFT_DIR)

fclean: clean
	$(RM) $(NAME)
	make fclean -C $(LIBFT_DIR)

re: fclean all
