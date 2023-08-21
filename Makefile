# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seunlee2 <seunlee2@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/29 17:31:22 by seunlee2          #+#    #+#              #
#    Updated: 2023/08/21 19:20:00 by seunlee2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
SRCS = so_long.c
OBJS = $(SRCS:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFT = libft
MLX = mlx

%.o: %.c
	$(CC) $(CFLAGS) -I $(LIBFT) -o $@ -c $< 

$(NAME): $(OBJS)
	$(MAKE) -C $(LIBFT)
	$(MAKE) -C $(MLX)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT)/libft.a -o $(NAME) -L./mlx $(MLX)/libmlx.a -framework OpenGL -framework Appkit

all: $(NAME)

clean:
	$(MAKE) -C $(LIBFT) clean
	$(MAKE) -C $(MLX) clean
	rm -f $(OBJS)

fclean: clean
	$(MAKE) -C $(LIBFT) fclean
	$(MAKE) -C $(MLX) fclean
	rm -f $(NAME)

re:
	$(MAKE) fclean
	$(MAKE)

.PHONY: all clean fclean re