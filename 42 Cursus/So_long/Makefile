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

# NAME PROJECT
NAME		= so_long
 
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
L_DIR		= ./Libft	
LIBFT		= -L$(L_DIR) -lft
HEADER		= inc/so_long.h
M_DIR		= ./Minilibx
Minilibx	= -L$(M_DIR) -lmlx -lXext -lX11 -lm


# COLORS
RESET		= \033[0m
RED			= \033[31m
BLUE		= \033[34m
YELLOW		= \033[33m
ORANGE		= \033[38;5;208m
GREEN		= \033[32m

# FILES
S_FILES		= ./SRCS/main.c						\
		  	./SRCS/Error/error_handler.c		\
		  	./SRCS/Error/validate_map.c			\
		  	./SRCS/Error/validate_string.c		\
		  	./SRCS/Error/validate_utils.c		\
		  	./SRCS/Error/validate_rest.c		\
		  	./SRCS/ft_free.c 					\

S_OBJ		= $(S_FILES:.c=.o)

all:	$(NAME)

$(NAME): $(S_OBJ) $(LIBFT) $(Minilibx)
		 $(CC) $(CFLAGS) -o $(NAME) $(S_OBJ) $(LIBFT) $(Minilibx)
		 clear
		 @echo "$(GREEN) COMPILATION COMPLETE$(RESET)"

%.o: %.c $(HEADER)
		 $(CC) $(CFLAGS) -c -o $@ $<

$(LIBFT):
		 @$(MAKE) -C $(L_DIR)

$(Minilibx):
		 @$(MAKE) -C $(M_DIR)

clean:
		@$(MAKE) clean -C $(L_DIR)
		rm -f $(S_OBJ)
		clear
		@$(MAKE) clean -C $(M_DIR)
		clear
		@echo "$(ORANGE) CLEANING THE OBJECTS$(RESET)"

fclean: clean
		@$(MAKE) fclean -C $(L_DIR)
		rm -f $(NAME)
		clear
		@echo "$(RED) CLEARING ALL FILES$(RESET)"

re: fclean all

.PHONY: all clean fclean re
