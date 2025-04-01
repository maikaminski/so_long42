# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: makamins <makamins@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/01 15:25:50 by makamins          #+#    #+#              #
#    Updated: 2025/04/01 15:28:06 by makamins         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = gnl.a
FLAGS = -Wall -Wextra -Werror -I .
SRC = get_next_line_utils.c get_next_line.c
CC = cc
OBJS = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@ 

clean:
	rm -f $(OBJS)
	
fclean: clean
	rm -f $(NAME)
	
re: fclean all

.PHONY: all clean fclean re