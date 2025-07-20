NAME = cub3D
CC = cc
FLAGS = -Wall -Werror -Wextra -g3 #-O2 -fsanitize=address,leak
RM = rm -rf
LIBFT = library/libft/libft.a
LIBFT_FLAGS = -L./library/libft -lft
MLX_FLAGS = -L./minilibx-linux -lmlx -lbsd -lXext -lX11 -lm

SRCS	=	main.c\
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
			src/game/texture.c\



RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
BLUE = \033[0;34m
MAGENTA = \033[0;35m
CYAN = \033[0;36m
RESET = \033[0m

OBJS = $(SRCS:.c=.o)
OBJS := $(addprefix obj/, $(OBJS))
OBJ_DIRS = $(sort $(dir $(OBJS)))

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
	#@clear
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

$(LIBFT):
	@make -s -C library/libft

$(OBJ_DIRS):
	@mkdir -p $@

obj/%.o: %.c | $(OBJ_DIRS)
	@$(CC) $(FLAGS) -c $< -o $@

all: $(NAME)

minilibx :
	@git clone "https://github.com/42Paris/minilibx-linux.git"
	cd minilibx-linux && make

clear:
	@$(RM) $(OBJS)

clean: clear
	@make -s -C library/libft clean

fclean: clean
	@$(RM) $(NAME) obj/
	@make -s -C library/libft fclean

re: fclean all

.PHONY: all minilibx clean fclean re clear