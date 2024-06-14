/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <sde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 11:18:21 by sde-carv          #+#    #+#             */
/*   Updated: 2024/06/14 11:18:24 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *s, ...);
int		ft_formats(va_list args, const char format);
int		ft_printchar(int c);
int		ft_printstr(char *str);
int		ft_printnbr(int n);

char	*ft_itoa(int n);

void	ft_putchar(const char c);
void	ft_putstr(const char *s);
void	ft_print_unsigned(unsigned int n, int *len);
void	ft_print_point(unsigned long long p, int *len);
void	ft_print_hex(unsigned int n, const char c, int *len);
void	ft_print_hexux(unsigned long long n, int *len);

#endif
