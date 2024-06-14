# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sde-carv <sde-carv@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/10 17:03:42 by sde-carv          #+#    #+#              #
#    Updated: 2024/06/14 15:30:27 by sde-carv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER = server
CLIENT = client

CC = cc
CFLAGS = -Wall -Wextra -Werror

PRINTF_DIR = ./ft_printf

HEADERS = minitalk.h $(PRINTF_DIR)/ft_printf.h

S_FILE = server.c
S_OBJS = $(S_FILE:.c=.o)

C_FILE = client.c ft_check.c
C_OBJS = $(C_FILE:.c=.o)

PRINTF_FILES = $(PRINTF_DIR)/ft_printf.c \
               $(PRINTF_DIR)/ft_printf_display.c \
               $(PRINTF_DIR)/ft_printf_hex.c \
               $(PRINTF_DIR)/ft_printf_utils.c
PRINTF_OBJS = $(PRINTF_FILES:.c=.o)

all: $(SERVER) $(CLIENT)

$(PRINTF_FILES): 
			$(PRINTF_FILES) $(PRINTF_DIR)/ft_printf.h
			$(CC) $(CFLAGS) -c $(PRINTF_FILES)

$(SERVER): $(S_OBJS)
			$(CC) $(CFLAGS) -o $(SERVER) $(S_OBJS) $(PRINTF_OBJS)

$(CLIENT): $(C_OBJS)
			$(CC) $(CFLAGS) -o $(CLIENT) $(C_OBJS) $(PRINTF_OBJS)

$(S_OBJS): $(S_FILE) $(HEADERS)
			$(CC) $(CFLAGS) -c $(S_FILE)

$(C_OBJS): $(C_FILE) $(HEADERS)
			$(CC) $(CFLAGS) -c $(C_FILE)

clean: 
		rm -f $(S_OBJS) $(C_OBJS) $(PRINTF_OBJS)

fclean: 
		clean rm -f $(SERVER) $(CLIENT)

re: fclean all

.PHONY: all clean fclean re
