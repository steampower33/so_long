# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seunlee2 <seunlee2@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/27 17:02:34 by seunlee2          #+#    #+#              #
#    Updated: 2023/08/28 12:24:20 by seunlee2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRCS = ft_printf.c ft_printf_util.c ft_putnbr.c
OBJECTS = $(SRCS:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

$(NAME): $(OBJECTS)
	ar -rcs $@ $^

all: $(NAME)

clean: 
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re:
	$(MAKE) fclean
	$(MAKE)

.PHONY: all clean fclean re