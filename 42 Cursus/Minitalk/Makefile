# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sde-carv <sde-carv@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/10 17:03:42 by sde-carv          #+#    #+#              #
#    Updated: 2024/06/15 13:28:07 by sde-carv         ###   ########.fr        #
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
PRINTF_OBJS = $(PRINTF_FILES:$(PRINTF_DIR)/%.c=$(PRINTF_DIR)/%.o)

UTILS_FILE = ft_utils.c
UTILS_OBJS = $(UTILS_FILE:.c=.o)

all: $(SERVER) $(CLIENT)

$(PRINTF_DIR)/%.o: $(PRINTF_DIR)/%.c $(HEADERS)
	$(CC) $(CFLAGS) -c -o $@ $<

$(UTILS_OBJS): $(UTILS_FILE) $(HEADERS)
	$(CC) $(CFLAGS) -c -o $(UTILS_OBJS) $(UTILS_FILE)

$(SERVER): $(S_OBJS) $(PRINTF_OBJS) $(UTILS_OBJS)
	$(CC) $(CFLAGS) -o $(SERVER) $(S_OBJS) $(PRINTF_OBJS) $(UTILS_OBJS)

$(CLIENT): client.o ft_check.o $(PRINTF_OBJS) $(UTILS_OBJS)
	$(CC) $(CFLAGS) -o $(CLIENT) client.o ft_check.o $(PRINTF_OBJS) $(UTILS_OBJS)

client.o: client.c $(HEADERS)
	$(CC) $(CFLAGS) -c -o client.o client.c

ft_check.o: ft_check.c $(HEADERS)
	$(CC) $(CFLAGS) -c -o ft_check.o ft_check.c

$(S_OBJS): $(S_FILE) $(HEADERS)
	$(CC) $(CFLAGS) -c -o $@ $<

clean: 
	/bin/rm -f $(S_OBJS) $(C_OBJS) $(PRINTF_DIR)/*.o $(UTILS_OBJS)

fclean: clean
	/bin/rm -f $(SERVER) $(CLIENT)

re: fclean all

.PHONY: all clean fclean re
