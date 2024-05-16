# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/14 12:37:53 by sde-carv          #+#    #+#              #
#    Updated: 2024/05/14 12:47:44 by sde-carv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = 

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
