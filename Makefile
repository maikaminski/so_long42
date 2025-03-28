# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: makamins <makamins@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/24 17:38:11 by makamins          #+#    #+#              #
#    Updated: 2025/03/28 14:53:19 by makamins         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
FLAGS = -Wall -Wextra -Werror -g
SRC = so_long.c
CC = cc
MLX_DIR = ./MLX42
MLX_FLAGS = -I$(MLX_DIR)/include -L$(MLX_DIR)/build -lmlx42 -ldl -lglfw -pthread -lm

OBJS = $(SRC:%.c=%.o)

all: $(NAME)
	
$(NAME): $(OBJS) 
	$(CC) $(FLAGS) -o $(NAME) $(OBJS) $(MLX_FLAGS)
	chmod +x $(NAME) 

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)


fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re 