/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 16:18:56 by sde-carv          #+#    #+#             */
/*   Updated: 2024/09/10 16:43:49 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>

void	ft_putchar(char c, int *len)
{
	write(1, &c, 1);
	(*len)++;
}

void	ft_putstr(char *str, int *len)
{
	int	i = -1;

	if (str == NULL)
	{
		ft_putstr("(null)", len);
		return ;
	}
	while (str[++i])
		ft_putchar(str[i], len);
}

void	ft_putnbr(int n, int *len)
{
	if (n == -2147483648)
	{
		ft_putstr("-2147483648", len);
		return ;
	}
	if (n < 0)
	{
		n = -n;
		ft_putchar('-', len);
	}
	if (n > 9)
		ft_putnbr((n / 10), len);
	ft_putchar(((n % 10) + '0'), len);
}

void	ft_print_hex(unsigned int n, int *len)
{
	char	digit[] = "0123456789abcdef";
	if (n >= 16)
		ft_print_hex((n / 16), len);
	ft_putchar(digit[n % 16], len);
}

void	check_type(va_list va, char c, int *len)
{
	if (c == 's')
		ft_putstr(va_arg(va, char *), len);
	if (c == 'd')
		ft_putnbr(va_arg(va, int), len);
	if (c == 'x')
		ft_print_hex(va_arg(va, unsigned int), len);
}

int ft_printf(const char *str, ... )
{
	int	i;
	va_list	va;
	int	len;

	i = -1;
	len = 0;
	va_start(va, str);
	while (str[++i])
	{
		if (str[i] == '%')
			check_type(va, str[++i], &len);
		else
			ft_putchar(str[i], &len);
	}
	va_end(va);
	return (len);
}

