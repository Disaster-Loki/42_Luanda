/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <sde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 17:04:51 by sde-carv          #+#    #+#             */
/*   Updated: 2024/06/17 09:15:58 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>

// Colors
# define COLOR_RESET "\033[0m"
# define COLOR_RED "\033[38;2;255;0;0m"
# define COLOR_YELLOW "\033[38;2;255;255;0m"
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
// Prototipe Functions
void	ft_putnbr(int n);
int		ft_isdigit(int c);
int		ft_atoi(char *ptr);
void	ft_putchar(char c);
void	ft_check(int av, char **arg);
void	ft_putstr(char *str, char *color);

#endif
