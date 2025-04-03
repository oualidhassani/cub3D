SRC = \
    src/main.c \
    src/start_game.c \
	src/ray_init.c \
	src/init_player.c \
	src/update_player.c \
	src/rendering.c \
	src/cast.c \
	src/cast_helper.c \
	src/draw_floor.c \
	src/draw_ceiling.c \
	src/exit_handlers.c \
	src/player_movements.c \
	src/player_position.c \
	src/init_texture_helpers.c \
	src/refreshing.c \
	src/chtaba.c \
	src/update_player_helper.c \
	src/verify_texture.c \
	src/init_check_points.c \
	src/textures_init.c \
	src/fish_eye_correction.c \
	src/shading.c \
    parsing/parsing_v0.c \
    parsing/parsing_v1.c \
    parsing/parsing_v2.c \
    parsing/parsing_v3.c \
    parsing/utils_v0.c \
    parsing/utils_v1.c \

OBJ = $(SRC:.c=.o)


LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

CFLAGS = -Wall -Wextra -Werror -fsanitize=address

RM = rm  
NAME = cub3D

all : $(NAME)

$(LIBFT):
	@echo "compiling libft"
	@$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJ) $(LIBFT)
	@echo "compiling $(NAME)"
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)
	@sleep 1
	@echo "$(NAME) compiled successfully."

%.o: %.c
	@$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -Imlx -c $< -o $@

clean:
	@echo cleaning object files ...
	rm -f $(OBJ) && rm -f libft/*.o
	@sleep 0.5
	@echo object files cleaned.

fclean : clean
	@echo full cleaning of $(NAME) ...
	@$(RM) -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@sleep 0.5
	@echo $(NAME) cleaned.

re: fclean all