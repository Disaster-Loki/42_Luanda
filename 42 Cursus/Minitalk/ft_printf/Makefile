# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xjose <xjose@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/21 11:51:15 by xjose             #+#    #+#              #
#    Updated: 2024/05/21 12:07:42 by xjose            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_printf

APP = app

src = *.c

OBJ = *.o

CC = gcc

CFLAGS = -Wall -Wextra -Werror

all: $(APP)

$(APP):
	$(CC) $(CFLAGS) -c $(src) -I ./
	$(CC) $(CFLAGS) $(OBJ) -o $(APP)
	rm -f $(OBJ)
	clear

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(APP)

re: fclean all
