# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcaquart <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/09 11:58:36 by mcaquart          #+#    #+#              #
#    Updated: 2024/05/10 15:49:37 by mcaquart         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
SRC = ft_display_file.c
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
EXEC = ft_display_file
OBJ = program

all: $(SRC)
	$(CC) -c $(SRC) -o $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(EXEC)
clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(EXEC)

re: fclean all
