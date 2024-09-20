# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/13 17:04:22 by sde-carv          #+#    #+#              #
#    Updated: 2024/09/13 17:04:25 by sde-carv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= philo

CC 			= cc
CFLAGS		= -Wall -Wextra -Werror

RESET		= \033[0m
RED			= \033[31m
BLUE		= \033[34m
YELLOW		= \033[33m
ORANGE		= \033[38;5;208m
GREEN		= \033[32m

S_FILES		= ./main.c   			\
			  ./utils.c  			\
			  ./error_handler.c 	\
			  ./philo_init.c 		\
			  ./stages.c 			\
			  ./stages_utils.c 		\
			  ./philo_stages.c 		\

S_OBJ		= $(S_FILES:.c=.c)

all: $(NAME)

$(NAME): $(S_OBJ)
		$(CC) $(CFLAGS) -o $(NAME) $(S_OBJ)
		clear
		@echo "$(GREEN) MANDATORY - COMPILATION COMPLETE$(RESET)"

clean: 	
		rm -f $(S_OBJ)
		clear
		@echo "$(ORANGE) CLEANING THE OBJECTS$(RESET)"

fclean:	
		rm -f $(NAME)
		clear
		@echo "$(RED) CLEARING ALL FILES$(RESET)"

re: fclean all
