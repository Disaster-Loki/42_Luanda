# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sde-carv <sde-carv@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/08 14:53:47 by sde-carv          #+#    #+#              #
#    Updated: 2024/05/08 15:57:39 by sde-carv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = ./srcs/ft_putchar.c ./srcs/ft_putstr.c ./srcs/ft_strcmp.c ./srcs/ft_strlen.c ./srcs/ft_swap.c

INDIR = ./includes/

CC = gcc

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): 
		$(CC) $(CFLAGS) -c $(SRCS) -I $(INDIR)
		ar rc $(NAME) *.o

clean: 
	rm -f *.o

fclean: clean
		rm -f $(NAME)
		rm -f $(INDIR)*.*.gcb

re: fclean all
