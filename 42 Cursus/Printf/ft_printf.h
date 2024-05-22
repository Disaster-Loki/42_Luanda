/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <sde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 13:07:59 by sde-carv          #+#    #+#             */
/*   Updated: 2024/05/20 08:47:25 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stddef.h>
# include <unistd.h>
# include "./Libft/libft.h"

int	ft_print_char(char c);
int	ft_print_string(char *str);
int	ft_print_pointer(unsigned long ptr, int base);
int	ft_print_int(int n);
int	ft_print_unsigned(unsigned int nb);
int	ft_print_hex(unsigned int n, int base);
int	ft_printf(const char *str, ...);

#endif
