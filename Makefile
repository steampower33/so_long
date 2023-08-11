# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seunlee2 <seunlee2@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/29 17:31:22 by seunlee2          #+#    #+#              #
#    Updated: 2023/08/11 19:38:27 by seunlee2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
SRCS = so_long.c
OBJS = $(SRCS:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFT_PATH = libft

%.o: %.c
	$(CC) $(CFLAGS) -I $(LIBFT_PATH) -o $@ -c $<

$(NAME): $(OBJS)
	$(MAKE) -C $(LIBFT_PATH)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_PATH)/libft.a -o $(NAME)

all: $(NAME)

clean:
	$(MAKE) -C $(LIBFT_PATH) clean
	rm -f $(OBJS)

fclean: clean
	$(MAKE) -C $(LIBFT_PATH) fclean
	rm -f $(NAME)

re:
	$(MAKE) fclean
	$(MAKE)

.PHONY: all clean fclean re