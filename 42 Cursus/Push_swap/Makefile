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

# Colors
RED		= \033[31m
BLUE	= \033[34m
RESET	= \033[0m
GREEN	= \033[32m
YELLOW	= \033[33m

HEADER  = ./inc/push_swap.h

# Files
S_FILES = ./src/error_handler.c 	\
		  ./src/error_utils.c 		\
		  ./src/index.c				\
 		  ./src/lst_utils.c  		\
		  ./src/radix.c				\
		  ./src/rotate.c 			\
		  ./src/reverse.c 			\
		  ./src/push.c 				\
		  ./src/stack_init.c		\
		  ./src/stack_sort.c		\
 		  ./src/stack_utils.c 		\
		  ./src/swap.c 				\
		  ./src/push_swap.c  		\

U_FILES = ./utils/ft_print.c 		\
			./utils/ft_split.c 		\
			./utils/ft_free.c 		\

S_OBJ   = $(S_FILES:.c=.o)
U_OBJ   = $(U_FILES:.c=.o)

all: $(NAME)

$(NAME): $(S_OBJ) $(U_OBJ)
	@$(CC) $(CFLAGS) -o $(NAME) $(S_OBJ) $(U_OBJ)
	@clear
	@echo "$(GREEN)COMPILATION COMPLETE!$(RESET)"

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c -o $@ $<
	@clear

clean:
	@if [ -f $(NAME) ]; then \
		rm -f $(S_OBJ) $(U_OBJ); \
		echo "$(YELLOW)OBJECT FILES CLEANED!$(RESET)"; \
	else \
		echo "$(RED)NOTHING TO CLEAN$(RESET)"; \
	fi

fclean: clean
	@if [ -f $(NAME) ]; then \
		rm -f $(NAME); \
		echo "$(BLUE)ALL FILES CLEANED!$(RESET)"; \
	fi

re: fclean
	@clear
	$(MAKE) --no-print-directory all

.PHONY: all clean fclean re




