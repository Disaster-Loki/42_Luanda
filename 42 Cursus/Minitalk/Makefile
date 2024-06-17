# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sde-carv <sde-carv@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/10 17:03:42 by sde-carv          #+#    #+#              #
#    Updated: 2024/06/17 09:22:22 by sde-carv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER = server
CLIENT = client

CC = cc
CFLAGS = -Wall -Wextra -Werror

HEADERS = minitalk.h

S_FILES = server.c
S_OBJS = $(S_FILES:.c=.o)

C_FILES = client.c ft_check.c
C_OBJS = $(C_FILES:.c=.o)

UTILS_FILES = ft_utils.c
UTILS_OBJS = $(UTILS_FILES:.c=.o)

all: $(SERVER) $(CLIENT)

$(UTILS_OBJS): $(UTILS_FILES) $(HEADERS)
	$(CC) $(CFLAGS) -c -o $@ $<

$(SERVER): $(S_OBJS) $(UTILS_OBJS)
	$(CC) $(CFLAGS) -o $(SERVER) $(S_OBJS) $(UTILS_OBJS)

$(CLIENT): $(C_OBJS) $(UTILS_OBJS)
	$(CC) $(CFLAGS) -o $(CLIENT) $(C_OBJS) $(UTILS_OBJS)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c -o $@ $<

clean: 
	/bin/rm -f $(S_OBJS) $(C_OBJS) $(UTILS_OBJS)

fclean: clean
	/bin/rm -f $(SERVER) $(CLIENT)

re: fclean all

.PHONY: all clean fclean re
