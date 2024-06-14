# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sde-carv <sde-carv@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/10 17:03:42 by sde-carv          #+#    #+#              #
#    Updated: 2024/06/14 12:52:11 by sde-carv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER = server
CLIENT = client

CC = cc
CFLAGS = -Wall -Wextra -Werror

HEADERS = 
PRINTF = ./ft_printf/
# Files
S_FILE = server.c
S_OBJS = $(S_FILE:.c=.o)

C_FILE = client.c ft_check.c
C_OBJS = $(C_FILE=.c=.o)

all: $(SERVER) $(CLIENT)

$(SERVER): $(S_OBJS)
		$(CC) $(CFLAGS) -o $(SERVER)

$(CLIENT): $(C_OBJS)
		$(CC) $(CFLAGS) -o $(CLIENT)
		
clean: 
		rm -f $(S_OBJS) $(C_OBJS)

fclean:
		rm -f $(SERVER) $(CLIENT)

re: fclean all

