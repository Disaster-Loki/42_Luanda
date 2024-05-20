/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <sde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 18:06:14 by sde-carv          #+#    #+#             */
/*   Updated: 2024/05/20 13:37:22 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "header.h"

void	test_char(void)
{
	char	c;

	c = 'A';
	ft_printf("Test char:\n");
	printf("printf: |%c|\n", c);
	ft_printf("ft_printf: |%c|\n", c);
}

void	test_string(void)
{
	char	*str;

	str = "Hello, World!";
	ft_printf("Test string:\n");
	printf("printf: |%s|\n", str);
	ft_printf("ft_printf: |%s|\n", str);
}

void	test_pointer(void)
{
	char	*str;
	void	*ptr;

	str = "Hello, World!";
	ptr = (void *)str;
	ft_printf("Test pointer:\n");
	printf("printf: |%p|\n", ptr);
	ft_printf("ft_printf: |%p|\n", ptr);
	printf("\n");
}

void	test_int(void)
{
	int	n;

	n = 42;
	ft_printf("Test int:\n");
	printf("printf: |%d|\n", n);
	ft_printf("ft_printf: |%d|\n", n);
}

void	test_unsigned(void)
{
	unsigned int	n;

	n = 42;
	ft_printf("Test unsigned int:\n");
	printf("printf: |%u|\n", n);
	ft_printf("ft_printf: |%u|\n", n);
}

void	test_hex(void)
{
	unsigned int	n;

	n = 42;
	ft_printf("Test hex (lowercase):\n");
	printf("printf: |%x|\n", n);
	ft_printf("ft_printf: |%x|\n\n", n);
	ft_printf("Test hex (uppercase):\n");
	printf("printf: |%X|\n", n);
	ft_printf("ft_printf: |%X|\n", n);
}

void	test_mixed(void)
{
	char			c;
	char			*str;
	int				n;
	unsigned int	u;
	void			*ptr;

	c = 'A';
	str = "Hello";
	n = 42;
	u = 42;
	ptr = str;
	ft_printf("Test mixed:\n");
	printf("printf: |Char: %c\n", c);
	printf("printf: |String: %s\n", str);
	printf("printf: |Pointer: %p\n", ptr);
	printf("printf: |Int: %d\n", n);
	printf("printf: |Unsigned: %u\n", u);
	printf("printf: |Hex: %x|\n\n", n);
	ft_printf("printf: |Char: %c\n", c);
	ft_printf("printf: |String: %s\n", str);
	ft_printf("printf: |Pointer: %p\n", ptr);
	ft_printf("printf: |Int: %d\n", n);
	ft_printf("printf: |Unsigned: %u\n", u);
	ft_printf("printf: |Hex: %x|\n\n", n);
}

int	main(void)
{
	test_char();
	test_string();
	test_pointer();
	test_int();
	test_unsigned();
	test_hex();
	test_mixed();
	return (0);
}
