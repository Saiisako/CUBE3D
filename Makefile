NAME = cub3D
CC = cc
FLAGS = -Wall -Werror -Wextra -g3 #-O2 -fsanitize=address,leak
RM = rm -rf
LIBFT = library/libft/libft.a
LIBFT_FLAGS = -L./library/libft -lft
MLX_FLAGS = -L./minilibx-linux -lmlx -lbsd -lXext -lX11 -lm

SRCS = main.c\
	src/parsing/error.c\
	src/parsing/parsing.c\
	src/parsing/free_parsing.c\
	src/parsing/malloc_map.c\
	src/parsing/init.c\
	src/parsing/verif_colors.c\
	src/parsing/verif_id.c\
	src/parsing/verif_path.c\
	src/parsing/verif_path2.c\
	src/parsing/utils.c\
	src/parsing/check_borders.c\
	src/parsing/check_map.c\
	src/parsing/utils2.c\
	src/game/graphic.c\
	src/game/init_game.c\
	src/game/init_player.c\
	src/game/raycasting.c\
	src/game/input.c\
	src/game/movement.c\
	src/game/rendering.c\
	src/game/rotation.c\
	src/game/texture.c

BONUS_SRCS = bonus/main_bonus.c\
	bonus/src/parsing/error_bonus.c\
	bonus/src/parsing/parsing_bonus.c\
	bonus/src/parsing/free_parsing_bonus.c\
	bonus/src/parsing/malloc_map_bonus.c\
	bonus/src/parsing/init_bonus.c\
	bonus/src/parsing/verif_colors_bonus.c\
	bonus/src/parsing/verif_id_bonus.c\
	bonus/src/parsing/verif_path_bonus.c\
	bonus/src/parsing/verif_path2_bonus.c\
	bonus/src/parsing/utils_bonus.c\
	bonus/src/parsing/check_borders_bonus.c\
	bonus/src/parsing/check_map_bonus.c\
	bonus/src/parsing/utils2_bonus.c\
	bonus/src/game/graphic_bonus.c\
	bonus/src/game/init_game_bonus.c\
	bonus/src/game/init_player_bonus.c\
	bonus/src/game/raycasting_bonus.c\
	bonus/src/game/input_bonus.c\
	bonus/src/game/mouse_key_bonus.c\
	bonus/src/game/movement_bonus.c\
	bonus/src/game/rendering_bonus.c\
	bonus/src/game/rotation_bonus.c\
	bonus/src/game/texture_bonus.c

BONUS_OBJS := $(BONUS_SRCS:%.c=obj/%.o)

RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
BLUE = \033[0;34m
MAGENTA = \033[0;35m
CYAN = \033[0;36m
RESET = \033[0m

OBJS = $(SRCS:.c=.o)
OBJS := $(addprefix obj/, $(OBJS))

OBJ_DIRS = $(sort $(dir $(OBJS) $(BONUS_OBJS)))

TARGET = $(NAME)

define PRINT_LOADING
	@echo -n "$(GREEN)Compiling... [                    ] 0%%$(RESET)\r"
	@for i in $(shell seq 1 20); do \
		sleep 0.035; \
		printf "\r$(GREEN)Compiling... ["; \
		printf "%*s" $$i | tr ' ' '#'; \
		printf "%*s" $$((20-$$i)) | tr ' ' ' '; \
		printf "] $$(($$i*5))%%$(RESET)"; \
	done
	@echo "\r$(GREEN)Compiling... [####################] 100%%$(RESET)"
endef

$(NAME): $(LIBFT) $(OBJ_DIRS) $(OBJS)
	@$(PRINT_LOADING)
	@$(CC) $(FLAGS) -o $(NAME) $(OBJS) $(LIBFT_FLAGS) $(MLX_FLAGS)
	@echo " ██████╗██╗   ██╗██████╗ ███████╗$(GREEN)██████╗ ██████╗ $(RESET)"
	@echo "██╔════╝██║   ██║██╔══██╗██╔════╝$(GREEN)╚════██╗██╔══██╗$(RESET)"
	@echo "██║     ██║   ██║██████╔╝█████╗  $(GREEN) █████╔╝██║  ██║$(RESET)"
	@echo "██║     ██║   ██║██╔══██╗██╔══╝  $(GREEN) ╚═══██╗██║  ██║$(RESET)"
	@echo "╚██████╗╚██████╔╝██████╔╝███████╗$(GREEN)██████╔╝██████╔╝$(RESET)"
	@echo " ╚═════╝ ╚═════╝ ╚═════╝ ╚══════╝$(GREEN)╚═════╝ ╚═════╝ $(RESET)"

bonus: $(LIBFT) $(OBJ_DIRS) $(BONUS_OBJS)
	@$(PRINT_LOADING)
	@$(CC) $(FLAGS) -o $(NAME) $(BONUS_OBJS) $(LIBFT_FLAGS) $(MLX_FLAGS)
	@echo "$(CYAN)[BONUS BUILD COMPLETE]$(RESET)"

$(LIBFT):
	@make -s -C library/libft

$(OBJ_DIRS):
	@mkdir -p $@

obj/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(FLAGS) -c $< -o $@

all: $(NAME)

minilibx:
	@git clone "https://github.com/42Paris/minilibx-linux.git"
	cd minilibx-linux && make

clear:
	@$(RM) $(OBJS) $(BONUS_OBJS)

clean:
	@$(MAKE) -s clear
	@make -s -C library/libft clean

fclean: clean
	@$(RM) $(NAME) obj/
	@make -s -C library/libft fclean

re: fclean all

.PHONY: all minilibx clean fclean re clear bonus
