# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/20 09:48:32 by sde-carv          #+#    #+#              #
#    Updated: 2024/08/20 09:48:34 by sde-carv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= so_long
BONUS_NAME	= so_long_bonus
 
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
L_DIR		= ./libft	
LIBFT		= -L$(L_DIR) -lft
HEADER		= inc/so_long.h
M_DIR		= ./minilibx-linux
Minilibx	= -L$(M_DIR) -lmlx -lXext -lX11 -lm

RESET		= \033[0m
RED			= \033[31m
BLUE		= \033[34m
YELLOW		= \033[33m
ORANGE		= \033[38;5;208m
GREEN		= \033[32m

S_FILES		= ./src/main.c									\
		  	./src/ft_free.c 								\
		  	./src/get_map.c 								\
		  	./src/error/error_handler.c						\
		  	./src/error/validate_map.c						\
		  	./src/error/validate_string.c					\
		  	./src/error/validate_utils.c					\
		  	./src/error/validate_rest.c						\
		  	./src/window/window_init.c 						\
		  	./src/window/keyboard.c 						\
		  	./src/window/window_close.c 					\

B_FILES		= ./bonus/src/main_bonus.c						\
		  	./bonus/src/ft_free_bonus.c 					\
		  	./bonus/src/get_map_bonus.c 					\
		  	./bonus/src/error/error_handler_bonus.c			\
		  	./bonus/src/error/validate_map_bonus.c			\
		  	./bonus/src/error/validate_string_bonus.c		\
		  	./bonus/src/error/validate_utils_bonus.c		\
		  	./bonus/src/error/validate_rest_bonus.c			\
		  	./bonus/src/window/window_init_bonus.c 			\
		  	./bonus/src/window/keyboard_bonus.c 			\
		  	./bonus/src/window/window_close_bonus.c 		\
		  	./bonus/src/window/window_enemies_bonus.c 		\
		  	./bonus/src/window/window_utils_bonus.c 		\
		  	./bonus/src/window/move_enimies_bonus.c 		\

S_OBJ		= $(S_FILES:.c=.o)
B_OBJ		= $(B_FILES:.c=.o)

all:	$(NAME)

$(NAME): $(S_OBJ)
		 $(MAKE) -C $(L_DIR)
		 $(MAKE) -C $(M_DIR)
		 $(CC) $(CFLAGS) -o $(NAME) $(S_OBJ) $(LIBFT) $(Minilibx)
		 clear
		 @echo "$(GREEN) MANDATORY - COMPILATION COMPLETE$(RESET)"

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(B_OBJ)
		 $(MAKE) -C $(L_DIR)
		 $(MAKE) -C $(M_DIR)
		 $(CC) $(CFLAGS) -o $(BONUS_NAME) $(B_OBJ) $(LIBFT) $(Minilibx)
		 clear
		 @echo "$(GREEN) BONUS - COMPILATION COMPLETE$(RESET)"		

clean:
		@$(MAKE) clean -C $(L_DIR)
		@$(MAKE) clean -C $(M_DIR)
		rm -f $(S_OBJ)
		rm -f $(B_OBJ)
		clear
		@echo "$(ORANGE) CLEANING THE OBJECTS$(RESET)"

fclean: clean
		@$(MAKE) fclean -C $(L_DIR)
		rm -f $(NAME)
		rm -f $(BONUS_NAME)
		clear
		@echo "$(RED) CLEARING ALL FILES$(RESET)"

re: fclean all

re_bonus: fclean bonus

