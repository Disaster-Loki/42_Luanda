/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 09:32:24 by sde-carv          #+#    #+#             */
/*   Updated: 2023/11/19 09:37:18 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_number(char c)
{
	write(1, &c, 1);
}

void	comb_numbers(char a, char b, char c)
{
	print_number(a + '0');
	print_number(b + '0');
	print_number(c + '0');
	if (a == 7 && b == 8 && c == 9)
	{
		return ;
	}
	print_number(',');
	print_number(' ');
}

void	ft_print_comb(void)
{
	int	a;
	int	b;
	int	c;

	a = 0;
	while (a <= 7)
	{
		b = a + 1;
		while (b <= 8)
		{
			c = b + 1;
			while (c <= 9)
			{
				comb_numbers(a, b, c);
				c++;
			}
			b++;
		}
		a++;
	}
}
