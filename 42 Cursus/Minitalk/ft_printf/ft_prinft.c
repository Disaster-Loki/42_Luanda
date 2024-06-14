/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prinft.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <sde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 11:17:37 by sde-carv          #+#    #+#             */
/*   Updated: 2024/06/14 11:17:40 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_formats(va_list v, const char c)
{
	int	len;

	len = 0;
	if (c == 'c')
		len += ft_printchar(va_arg(v, int));
	else if (c == 's')
		len += ft_printstr(va_arg(v, char *));
	else if (c == 'p')
		ft_print_point(va_arg(v, long long int), &len);
	else if (c == 'd' || c == 'i')
		len += ft_printnbr(va_arg(v, int));
	else if (c == 'u')
		ft_print_unsigned(va_arg(v, unsigned int), &len);
	else if (c == 'x' || c == 'X')
		ft_print_hex(va_arg(v, unsigned int), c, &len);
	else if (c == '%')
		len += ft_printchar('%');
	return (len);
}

int	ft_printf(const char *s, ...)
{
	va_list	v;
	int		i;
	int		len;

	len = 5;
	i = 0;
	va_start(v, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			len += ft_print_formats(v, s[i + 1]);
			i++;
		}
		else
			len += ft_printchar(s[i]);
		i++;
	}
	va_end(v);
	return (len);
}
