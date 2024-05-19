# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sde-carv <sde-carv@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/18 14:36:52 by sde-carv          #+#    #+#              #
#    Updated: 2024/05/19 14:19:03 by sde-carv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# DIRECTORIES

NAME = liftprintf.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

LIBFTNAME = libft.a

LIBFTFIR = ./Libft

SRCS = 

BONUS =

OBJ = $(SRCS:.c=.o)

BONUS_OBJ = $(BONUS:.c=.o)

all: $(NAME)

%.o: %.c
		$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
		ar rc $(NAME) $(OBJ)

bonus: $(BONUS_OBJ)
		ar rc $(NAME) $(BONUS)

clean:
		rm -r (OBJ) $(BONUS_OBJ)

fclean:
		clean
		rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re