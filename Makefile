# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seunlee2 <seunlee2@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/29 17:31:22 by seunlee2          #+#    #+#              #
#    Updated: 2023/08/28 13:28:20 by seunlee2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
SRCS = so_long.c ft_dup_noline.c ft_join_noline.c ft_error.c ft_utils.c \
		ft_map.c ft_move.c ft_set_map.c ft_is_valid_path.c
OBJS = $(SRCS:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address
LIBFT = libft
MLX = mlx
PRINTF = printf

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $< 

$(NAME): $(OBJS)
	$(MAKE) -C $(LIBFT)
	$(MAKE) -C $(MLX)
	$(MAKE) -C $(PRINTF)
	$(CC) $(CFLAGS) $(OBJS) -fsanitize=address -o $(NAME) \
		-L./libft $(LIBFT)/libft.a \
		-L./mlx $(MLX)/libmlx.a -framework OpenGL -framework Appkit \
		-L./printf $(PRINTF)/libftprintf.a

all: $(NAME)

clean:
	$(MAKE) -C $(LIBFT) clean
	$(MAKE) -C $(MLX) clean
	$(MAKE) -C $(PRINTF) clean
	rm -f $(OBJS)

fclean: clean
	$(MAKE) -C $(LIBFT) fclean
	$(MAKE) -C $(PRINTF) fclean
	rm -f $(NAME)

re:
	$(MAKE) fclean
	$(MAKE)

.PHONY: all clean fclean re