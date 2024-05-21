/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <sde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 18:06:14 by sde-carv          #+#    #+#             */
/*   Updated: 2024/05/21 11:49:48 by sde-carv         ###   ########.fr       */
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
	ft_printf("Test pointer\n");
	printf("printf: |%p|\n", ptr);
	ft_printf("ft_printf: |%p|\n", ptr);
	printf("\n");

	void *ptr1 = (void *)0x1234abcd;
	void *ptr2 = (void *)0;
	
	ft_printf("Teste Pointer \n");
	ft_printf("Test pointer 1:\n");
	printf("printf: |%p|\n", ptr1);
	ft_printf("ft_printf: |%p|\n", ptr1);

	ft_printf("Test pointer 2:\n");
	printf("printf: |%p|\n", ptr2);
	ft_printf("ft_printf: |%p|\n", ptr2);
}

void	test_int(void)
{
	int	n;

	n = 42;
	ft_printf("Test int:\n");
	printf("printf: |%d|\n", n);
	ft_printf("ft_printf: |%d|\n", n);
	printf("printf: |%i|\n", n);
	ft_printf("ft_printf: |%i|\n", n);
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

void	test_percent(void)
{
	ft_printf("Teste Percent\n");
	printf("Printf: %%\n");
	ft_printf("ft_printf: %%\n");
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
	ft_printf("Test mixed\n");
	printf("printf\n |Char: %c\n |String: %s\n |Pointer: %p\n |Int: %d\n |Unsigned: %u\n|Hex: %x|\n\n", c, str, ptr, n, u, n);
	ft_printf("ft_printf\n |Char: %c\n |String: %s\n |Pointer: %p\n |Int: %d\n |Unsigned: %u\n|Hex: %x|\n\n", c, str, ptr, n, u, n);
	
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
	test_percent();
	return (0);
}
