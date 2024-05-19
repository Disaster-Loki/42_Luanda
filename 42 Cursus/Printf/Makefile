# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sde-carv <sde-carv@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/18 14:36:52 by sde-carv          #+#    #+#              #
#    Updated: 2024/05/19 16:15:57 by sde-carv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# DIRECTORIES

NAME = libftprintf.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

LIBFTNAME = libft.a

LIBFTFIR = ./Libft

SRCS = ft_printf.c \
		ft_print_pointer.c \
		ft_print_unsigned.c \
		ft_print_string.c \
		ft_print_int.c \
		ft_print_char.c \
		ft_print_hex.c \

#BONUS =
#BONUS_OBJ = $(BONUS:.c=.o)

OBJS = $(SRCS:.c=.o)

all: $(NAME)

makelibft:
	@make -C $(LIBFTDIR)
	@cp $(LIBFTDIR)/$(LIBFTNAME) .
	@mv $(LIBFTNAME) $(NAME)

$(NAME): makelibft $(OBJS)
	@ar -r $(NAME) $(OBJS)

clean:
	@rm -f $(OBJS)
	@cd $(LIBFTDIR) && make clean
	
fclean: clean
	@rm -f $(NAME)
	@cd $(LIBFTDIR) && make fclean
	
re: fclean all