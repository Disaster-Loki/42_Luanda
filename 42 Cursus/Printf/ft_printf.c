/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <sde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 13:18:05 by sde-carv          #+#    #+#             */
/*   Updated: 2024/05/19 16:07:43 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int	check_type(const char *input, void *arg)
{
	int	i;

	i = 0;
	if (*input == 'c')
		i += ft_print_char((int)arg);
	else if (*input == 's')
		i += ft_print_string((char *)arg);
	else if (*input == 'p')
		i += ft_print_pointer((unsigned long)arg, 87);
	else if (*input == 'd')
		i += ft_print_int((int)arg);
	else if (*input == 'i')
		i += ft_print_int((int)arg);
	else if (*input == 'u')
		i += ft_print_unsigned((unsigned int)arg);
	else if (*input == 'x')
		i += ft_print_hex((unsigned int)arg, 87);
	else if (*input == 'X')
		i += ft_print_hex((unsigned int)arg, 55);
	return (i);
}

int	ft_printf(const char *input, ...)
{
	va_list			args;
	unsigned int	i;

	i = 0;
	va_start(args, input);
	while (*input != '\0')
	{
		if (*input == '%')
		{
			input++;
			if (ft_strchr("cspdiuxX", *input))
				i += check_type(input, va_arg(args, void *));
			else if (*input == '%')
				i += ft_print_char('%');
		}
		else
			i = i + ft_print_char(*input);
		input++;
	}
	va_end(args);
	return (i);
}
