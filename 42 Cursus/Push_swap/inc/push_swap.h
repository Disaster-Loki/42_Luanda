/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 16:00:31 by sde-carv          #+#    #+#             */
/*   Updated: 2024/07/31 16:00:34 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include <unistd.h>

typedef struct stack
{
	int				content;
	int				index;
	struct stack	*next;
	struct stack	*prev;
}	t_stack;

// Colors
# define RESET "\033[0m"
# define DARK_BLUE "\033[38;2;0;0;139m"
# define AQUA "\033[38;2;0;255;255m"
# define SLATE_BLUE "\033[38;2;131;111;255m"
# define BLUE "\033[38;2;0;0;255m"
# define MEDIUM_BLUE "\033[38;2;0;0;205m"
# define LIME "\033[38;2;0;255;0m"
# define RED "\033[38;2;255;0;0m"
# define DARK_RED "\033[38;2;139;0;0m"
# define YELLOW "\033[38;2;255;255;0m"
# define DARK_ORANGE "\033[38;2;255;140;0m"
// utils
void	ft_putnbr(int n);
int		ft_atoi(char *str);
int		ft_isdigit(char c);
void	ft_putchar(char c);
int		ft_strlen(char *str);
void	free_split(char **split);
int		ft_toklen(char *str, char c);
char	**ft_split(char *str, char c);
void	ft_putstr(char	*str, char *color);
int		ft_strlcpy(char *dst, char *src, int size);
char	*ft_substr(char *s, unsigned int start, size_t len);
//src
void	error_handler(int av, char **args);

#endif
