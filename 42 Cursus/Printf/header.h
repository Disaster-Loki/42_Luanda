/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <sde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 13:07:59 by sde-carv          #+#    #+#             */
/*   Updated: 2024/05/19 16:23:07 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <stdarg.h>
# include <stddef.h>
# include <unistd.h>
# include "./Libft/libft.h"

int     ft_print_char(int c);
int     ft_print_string(char *str);
int     ft_print_pointer(unsigned long ptr, int base);
int     ft_print_int(int n);
int     ft_print_unsigned(unsigned int n);
int     ft_print_hex(unsigned int n, int base);
char    *ft_strchr(const char *s, int c);
int	    ft_printf(const char *str, ...);

#endif
