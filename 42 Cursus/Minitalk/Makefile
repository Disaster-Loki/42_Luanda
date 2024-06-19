# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sde-carv <sde-carv@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/10 17:03:42 by sde-carv          #+#    #+#              #
#    Updated: 2024/06/17 10:39:38 by sde-carv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER = server
CLIENT = client

SERVER_B = server_bonus
CLIENT_B = client_bonus

CC = cc
CFLAGS = -Wall -Wextra -Werror

HEADER = minitalk.h
HEADER_B = minitalk_bonus.h

S_FILES = server.c
S_OBJS = $(S_FILES:.c=.o)

BS_FILES = server_bonus.c
BS_OBJS = $(BS_FILES:.c=.o)

C_FILES = client.c ft_check.c
C_OBJS = $(C_FILES:.c=.o)

BC_FILES = client_bonus.c ft_check_bonus.c
BC_OBJS = $(BC_FILES:.c=.o)

UTILS_FILES = ft_utils.c
UTILS_OBJS = $(UTILS_FILES:.c=.o)

B_UTILS_FILES = ft_utils_bonus.c
B_UTILS_OBJS = $(B_UTILS_FILES:.c=.o)

all: $(SERVER) $(CLIENT)

bonus: $(SERVER_B) $(CLIENT_B)

$(UTILS_OBJS): $(UTILS_FILES) $(HEADER)
	$(CC) $(CFLAGS) -c -o $@ $<

$(B_UTILS_OBJS): $(B_UTILS_FILES) $(HEADER_B)
	$(CC) $(CFLAGS) -c -o $@ $<

$(SERVER): $(S_OBJS) $(UTILS_OBJS)
	$(CC) $(CFLAGS) -o $(SERVER) $(S_OBJS) $(UTILS_OBJS)

$(SERVER_B): $(BS_OBJS) $(B_UTILS_OBJS)
	$(CC) $(CFLAGS) -o $(SERVER_B) $(BS_OBJS) $(B_UTILS_OBJS)

$(CLIENT): $(C_OBJS) $(UTILS_OBJS)
	$(CC) $(CFLAGS) -o $(CLIENT) $(C_OBJS) $(UTILS_OBJS)

$(CLIENT_B): $(BC_OBJS) $(B_UTILS_OBJS)
	$(CC) $(CFLAGS) -o $(CLIENT_B) $(BC_OBJS) $(B_UTILS_OBJS)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c -o $@ $<

%.o: %.c $(HEADER_B)
	$(CC) $(CFLAGS) -c -o $@ $<

clean: 
	rm -f $(S_OBJS) $(C_OBJS) $(UTILS_OBJS) $(BS_OBJS) $(BC_OBJS) $(B_UTILS_OBJS)

fclean: clean
	rm -f $(SERVER) $(CLIENT) $(SERVER_B) $(CLIENT_B)

re: fclean all

.PHONY: all clean fclean re bonus
