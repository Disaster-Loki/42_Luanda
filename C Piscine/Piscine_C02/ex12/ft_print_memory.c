/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 10:35:09 by sde-carv          #+#    #+#             */
/*   Updated: 2023/11/28 12:06:56 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print(char c, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		write(1, &c, 1);
		i++;
	}
}

void	hex(unsigned long long nb, int prev)
{
	char	*base;

	base = "0123456789abcdef";
	if (nb < 16 && prev == 1)
	{
		print('0', 1);
	}
	if (nb >= 16)
	{
		hex(nb / 16, 0);
		hex(nb % 16, 0);
	}
	else
	{
		print(base[nb], 1);
	}
}

void	print_hex(unsigned long long str)
{
	unsigned long long	tmp;
	int					i;

	tmp = str;
	i = 1;
	while (i++ < 15)
	{
		if (tmp < 16)
		{
			print('0', 1);
		}
		tmp /= 16;
	}
	hex(str, 0);
}

void	print_hex_ascii(unsigned char *c, int size)
{
	int	i;

	i = -1;
	while (i++ < 16)
	{
		if (i % 2 == 0)
			print(' ', 1);
		if (i < size)
		{
			hex((unsigned long long)*(c + i), 1);
		}
		else if (i != 16)
		{
			print(' ', 2);
		}
	}
	i = -1;
	while (i++ < size - 1)
	{
		if (*(c + i) <= 31 || *(c + i) >= 127)
			print('.', 1);
		else
			print(*(c + i), 1);
	}
}

void	*ft_print_memory(void *str, unsigned int size)
{
	unsigned int	i;
	unsigned char	*c;
	unsigned int	sendsize;

	i = 0;
	c = str;
	while (i * 16 < size)
	{
		if (i < size / 16)
		{
			sendsize = 16;
		}
		else
		{
			sendsize = size % 16;
		}
		print_hex((unsigned long long)c + (i * 16));
		print(':', 1);
		print_hex_ascii(c + (i * 16), sendsize);
		print('\n', 1);
		i++;
	}
	return (str);
}
