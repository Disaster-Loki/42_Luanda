/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <sde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 13:18:05 by sde-carv          #+#    #+#             */
/*   Updated: 2024/05/21 16:31:22 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int	check_type(const char *input, va_list args)
{
	int	i;

	i = 0;
	if (*input == 'c')
		i += ft_print_char(va_arg(args, int));
	else if (*input == 's')
		i += ft_print_string(va_arg(args, char *));
	else if (*input == 'p')
		i += ft_print_pointer(va_arg(args, unsigned long), 87);
	else if (*input == 'd' || *input == 'i')
		i += ft_print_int(va_arg(args, int));
	else if (*input == 'u')
		i += ft_print_unsigned(va_arg(args, unsigned int));
	else if (*input == 'x')
		i += ft_print_hex(va_arg(args, unsigned int), 87);
	else if (*input == 'X')
		i += ft_print_hex(va_arg(args, unsigned int), 55);
	return (i);
}

static int	handle_width(const char **input)
{
	int	width;

	width = 0;
	while (**input >= '0' && **input <= '9')
	{
		width = width * 10 + (**input - '0');
		(*input)++;
	}
	return (width);
}

static int	print_percent_with_width(int width)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (i < width - 1)
	{
		count += ft_print_char(' ');
		i++;
	}
	count += ft_print_char('%');
	return (count);
}

static int	handle_conversion(const char **input, va_list args)
{
	int	width;
	int	count;

	count = 0;
	width = handle_width(input);
	if (**input == '%')
		count += print_percent_with_width(width);
	else if (ft_strchr("cspdiuxX%", **input))
		count += check_type(*input, args);
	return (count);
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
			i += handle_conversion(&input, args);
		}
		else
			i += ft_print_char(*input);
		input++;
	}
	va_end(args);
	return (i);
}
