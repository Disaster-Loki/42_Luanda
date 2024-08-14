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

# Files
S_FILES = ./src/error_handler.c 	\
		  ./src/error_utils.c 		\
		  ./src/index.c				\
 		  ./src/lst_utils.c  		\
		  ./src/rotate.c 			\
		  ./src/reverse.c 			\
		  ./src/push.c 				\
		  ./src/stack_init.c		\
		  ./src/stack_sort.c		\
 		  ./src/stack_utils.c 		\
		  ./src/swap.c 				\
		  ./src/push_swap.c  		\
		  ./src/case_stack_a.c 		\
		  ./src/case_stack_b.c 		\
		  ./src/rot_strat.c 		\
		  ./src/rot_strat_utils.c 	\

U_FILES = ./utils/ft_print.c 		\
			./utils/ft_split.c 		\
			./utils/ft_free.c 		\

S_OBJ   = $(S_FILES:.c=.o)
U_OBJ   = $(U_FILES:.c=.o)

all: $(NAME)

$(NAME): $(S_OBJ) $(U_OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(S_OBJ) $(U_OBJ)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(S_OBJ) $(U_OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re




