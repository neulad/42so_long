NAME := so_long
CC := cc
CC_FLAGS := -Wall -Wextra -Werror

SRC := main.c utils/error.c map/parse.c \
	utils/map_height.c utils/map_width.c map/validate/validate_border.c \
	map/validate/validate_size.c map/validate/validate.c utils/free_map.c \
	map/validate/validate_sprites.c game/init_map.c game/mlx_hooks.c \
	game/moves.c map/validate/validate_exit.c utils/find_sprite.c \
	utils/end_game.c
OBJS := $(SRC:.c=.o)

LIB_DIRS := libs/libft libs/minilibx libs/ft_printf
LIBS := ft mlx_Linux Xext X11 ftprintf
LIBS_FLAGS = $(addprefix -L, $(LIB_DIRS)) $(addprefix -l, $(LIBS))

MINILIBX_REPO := https://github.com/42Paris/minilibx-linux.git
MINILIBX_DIR := libs/minilibx

%.o: %.c
	@$(CC) $(CC_FLAGS) -c $< -o $@

all: $(MINILIBX_DIR) libs $(NAME) clean
$(MINILIBX_DIR):
	@if [ ! -d $(MINILIBX_DIR) ]; then \
		git clone $(MINILIBX_REPO) $(MINILIBX_DIR); \
		rm -rf libs/minilibx/.git; \
	fi
libs:
	@$(foreach dir, $(LIB_DIRS), make -C $(dir);)
$(NAME): $(OBJS)
	@$(CC) $(CC_FLAGS) $^ $(LIBS_FLAGS) -o $@
clean:
	@rm -rf $(OBJS)
	@$(foreach dir, $(LIB_DIRS), rm -rf $(dir)/*.o;)
fclean: clean
	@rm -rf $(NAME)
	@$(foreach dir, $(LIB_DIRS), rm -rf $(dir)/*.a;)
re: fclean all

.PHONY: all libs clean fclean re $(MINILIBX_DIR)
