# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sde-carv <sde-carv@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/16 14:51:47 by sde-carv          #+#    #+#              #
#    Updated: 2024/05/16 14:51:50 by sde-carv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c

HEADER = libft.h

CC = gcc

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(CC) $(CFLAGS) -C $(SRCS) -I $(header)
	ar rc $(NAME) *.o

clean: 
	rm -f *.o

fclean: clean
		rm -f $(NAME)
		rm -f $(HEADER)*.*.GCB

re: fckean all

.PHONY: all bonus clean fclean re
