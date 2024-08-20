# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/19 13:36:21 by sde-carv          #+#    #+#              #
#    Updated: 2024/08/19 13:36:27 by sde-carv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	=	libft.a
CC 		=	gcc
CFLAGS 	=	-Wall -Wextra -Werror

HEADER	=	./inc/libft.h

SRC 	= 	Is/ft_isalpha.c				\
			Is/ft_isdigit.c 			\
			Is/ft_isalnum.c 			\
			Is/ft_isascii.c 			\
			Is/ft_isprint.c 			\
			String/ft_strlen.c 			\
			Memory/ft_memset.c 			\
			Rest/ft_bzero.c				\
			Memory/ft_memcpy.c 			\
			Memory/ft_memmove.c 		\
			String/ft_strlcpy.c 		\
			String/ft_strlcat.c 		\
			Rest/ft_toupper.c 			\
			Rest/ft_tolower.c 			\
			String/ft_strchr.c 			\
			String/ft_strrchr.c 		\
			String/ft_strncmp.c 		\
			Memory/ft_memchr.c 			\
			Memory/ft_memcmp.c 			\
			String/ft_strnstr.c 		\
			Rest/ft_atoi.c 				\
			Rest/ft_calloc.c 			\
			String/ft_strdup.c 			\
			String/ft_substr.c 			\
			String/ft_strjoin.c 		\
			String/ft_strtrim.c 		\
			Rest/ft_split.c 			\
			Rest/ft_itoa.c 				\
			String/ft_strmapi.c 		\
			String/ft_striteri.c 		\
			Put/ft_putchar_fd.c 		\
			Put/ft_putstr_fd.c 			\
			Put/ft_putendl_fd.c 		\
			Put/ft_putnbr_fd.c			\

BONUS 	=	List/ft_lstnew.c 			\
			List/ft_lstadd_front.c 		\
			List/ft_lstsize.c 			\
			List/ft_lstlast.c 			\
			List/ft_lstadd_back.c 		\
			List/ft_lstdelone.c 		\
			List/ft_lstclear.c 			\
			List/ft_lstiter.c 			\
			List/ft_lstmap.c			\

OBJ 	=	$(SRC:.c=.o)
BONUS_OBJ = $(BONUS:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

bonus: $(BONUS_OBJ)
	ar rc $(NAME) $(BONUS_OBJ)
	ranlib $(NAME)

clean:
	/bin/rm -f $(OBJ) $(BONUS_OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re

