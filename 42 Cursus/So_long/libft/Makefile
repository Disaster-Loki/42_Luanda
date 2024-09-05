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
CC 		=	cc
CFLAGS 	=	-Wall -Wextra -Werror

HEADER	=	./inc/libft.h

SRC 	= 	is/ft_isalpha.c				\
			is/ft_isdigit.c 			\
			is/ft_isalnum.c 			\
			is/ft_isascii.c 			\
			is/ft_isprint.c 			\
			string/ft_strlen.c 			\
			memory/ft_memset.c 			\
			rest/ft_bzero.c				\
			memory/ft_memcpy.c 			\
			memory/ft_memmove.c 		\
			string/ft_strlcpy.c 		\
			string/ft_strlcat.c 		\
			rest/ft_toupper.c 			\
			rest/ft_tolower.c 			\
			string/ft_strchr.c 			\
			string/ft_strrchr.c 		\
			string/ft_strncmp.c 		\
			memory/ft_memchr.c 			\
			memory/ft_memcmp.c 			\
			string/ft_strnstr.c 		\
			rest/ft_atoi.c 				\
			rest/ft_calloc.c 			\
			string/ft_strdup.c 			\
			string/ft_substr.c 			\
			string/ft_strjoin.c 		\
			string/ft_strtrim.c 		\
			rest/ft_split.c 			\
			rest/ft_itoa.c 				\
			string/ft_strmapi.c 		\
			string/ft_striteri.c 		\
			put/ft_putchar_fd.c 		\
			put/ft_putstr_fd.c 			\
			put/ft_putendl_fd.c 		\
			put/ft_putnbr_fd.c			\

BONUS 	=	list/ft_lstnew.c 			\
			list/ft_lstadd_front.c 		\
			list/ft_lstsize.c 			\
			list/ft_lstlast.c 			\
			list/ft_lstadd_back.c 		\
			list/ft_lstdelone.c 		\
			list/ft_lstclear.c 			\
			list/ft_lstiter.c 			\
			list/ft_lstmap.c			\

OBJ 	=	$(SRC:.c=.o)
BONUS_OBJ = $(BONUS:.c=.o)

all: $(NAME)

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
