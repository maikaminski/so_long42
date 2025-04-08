# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: makamins <makamins@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/24 17:38:11 by makamins          #+#    #+#              #
#    Updated: 2025/04/08 17:03:54 by makamins         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
FLAGS = -Wall -Wextra -Werror -g
SRC = so_long.c load_images.c errors.c init_game.c map_validate.c \
		player_moves.c render_utils.c map_path.c
CC = cc
GNL = gnl/gnl.a
LIBFT = libft/libft.a
FT_PRINTF = ft_printf/ft_printf.a
MLX_DIR = ./MLX42
MLX_FLAGS = -I$(MLX_DIR)/include -L$(MLX_DIR)/build -lmlx42 -ldl -lglfw -pthread -lm

OBJS = $(SRC:%.c=%.o)

all: $(NAME)

$(GNL):
	@make -C gnl
$(FT_PRINTF):
	@make -C ft_printf
$(LIBFT):
	@make -C libft
$(MLX_DIR)/build/libmlx42.a:
	@mkdir -p $(MLX_DIR)/build
	@cd $(MLX_DIR) && cmake -B build && cmake --build build -j4

$(NAME): $(OBJS) $(GNL) $(LIBFT) $(FT_PRINTF) $(MLX_DIR)/build/libmlx42.a
	$(CC) $(FLAGS) -o $(NAME) $(OBJS) $(MLX_FLAGS) $(GNL) $(LIBFT) $(FT_PRINTF)
	chmod +x $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	@make clean -C gnl
	@make clean -C libft
	@make clean -C ft_printf


fclean: clean
	rm -f $(NAME)
	@make fclean -C gnl
	@make clean -C libft
	@make clean -C ft_printf

re: fclean all

.PHONY: all clean fclean re 

# valgrind --leak-check=full \
#          --show-leak-kinds=all \
#          --track-origins=yes \
#          --suppressions=mlx.supp \
#          ./so_long maps/map1.ber 2>&1 | grep -A20 "LEAK SUMMARY"
