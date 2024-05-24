/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <sde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 13:07:59 by sde-carv          #+#    #+#             */
/*   Updated: 2024/05/24 13:49:02 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>
// Libs functions
int		ft_print_int(int n);
char	*ft_itoa(int n);
int		ft_print_char(char c);
int		ft_print_string(char *str);
size_t	ft_strlen(const char *str);
void	ft_bzero(void *s, size_t n);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
int		ft_printf(const char *str, ...);
char	*ft_strchr(const char *s, int n);
int		ft_print_unsigned(unsigned int nb);
void	*ft_memset(void *s, int c, size_t n);
void	*ft_calloc(size_t count, size_t size);
int		ft_print_hex(unsigned int n, int base);
int		ft_print_pointer(unsigned long ptr, int base);

#endif
