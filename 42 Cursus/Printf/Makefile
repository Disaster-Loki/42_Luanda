# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sde-carv <sde-carv@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/18 14:36:52 by sde-carv          #+#    #+#              #
#    Updated: 2024/05/19 16:20:04 by sde-carv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# DIRECTORIES

NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

LIBFTNAME = libft.a
LIBFTDIR = ./Libft

SRCS = ft_printf.c \
       ft_print_pointer.c \
       ft_print_unsigned.c \
       ft_print_string.c \
       ft_print_int.c \
       ft_print_char.c \
       ft_print_hex.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): makelibft $(OBJS)
	@cp $(LIBFTDIR)/$(LIBFTNAME) .
	@mv $(LIBFTNAME) $(NAME)
	@ar -r $(NAME) $(OBJS)

makelibft:
	make -C $(LIBFTDIR)

clean:
	rm -f $(OBJS)
	@cd $(LIBFTDIR) && make clean

fclean: clean
	rm -f $(NAME)
	@cd $(LIBFTDIR) && make fclean

re: fclean all
