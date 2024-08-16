# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/31 15:58:54 by sde-carv          #+#    #+#              #
#    Updated: 2024/08/04 13:39:34 by sde-carv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = push_swap
CC      = cc
CFLAGS  = -Wall -Werror -Wextra

HEADER  = ./inc/push_swap.h

# Colors
RESET	= \033[0m
RED		= \033[31m
BLUE	= \033[34m
YELLOW	= \033[33m
ORANGE	= \033[38;5;208m
GREEN	= \033[32m

# Files
S_FILES = ./src/error_handler.c 	\
		  ./src/error_utils.c 		\
		  ./src/index.c				\
 		  ./src/lst_utils.c  		\
		  ./src/rotate.c 			\
		  ./src/reverse.c 			\
		  ./src/push.c 				\
		  ./src/stack_init.c		\
		  ./src/swap.c 				\
		  ./src/push_swap.c  		\

U_FILES = ./utils/ft_print.c 		\
		  ./utils/ft_split.c 		\
		  ./utils/ft_free.c 		\

A_FILES = ./sort/case_stack_a.c 	\
		  ./sort/case_stack_b.c 	\
		  ./sort/rot_strat.c 		\
		  ./sort/rot_strat_utils.c 	\
		  ./sort/stack_sort.c		\
 		  ./sort/stack_utils.c 		\

S_OBJ   = $(S_FILES:.c=.o)
U_OBJ   = $(U_FILES:.c=.o)
A_OBJ	= $(A_FILES:.c=.o);

all: $(NAME)

$(NAME): $(S_OBJ) $(U_OBJ) $(A_OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(S_OBJ) $(U_OBJ) $(A_OBJ)
	clear
	@echo "$(GREEN) Compilation Complete$(RESET)"

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(S_OBJ) $(U_OBJ) $(A_OBJ)
	clear
	@echo "$(ORANGE) Cleaning the Objects$(RESET)"

fclean: clean
	rm -f $(NAME)
	clear
	@echo "$(RED) Clearing All Files$(RESET)"

re: fclean all

.PHONY: all clean fclean re
