/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 10:53:49 by sde-carv          #+#    #+#             */
/*   Updated: 2023/11/19 09:40:10 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print(char c)
{
	write(1, &c, 1);
}

void	comb_numbers(int a)
{
	int	i;
	int	k;

	if (a <= 9)
	{
		print('0');
		print(a + '0');
	}
	else
	{
		i = (int) a / 10;
		k = (int) a % 10;
		print(i + '0');
		print(k + '0');
	}
}

void	ft_print_comb2(void)
{
	int	a;
	int	b;

	a = 0;
	while (a <= 98)
	{
		b = a + 1;
		while (b <= 99)
		{
			comb_numbers(a);
			print(' ');
			comb_numbers(b);
			if (a != 98 || b != 99)
			{
				print(',');
				print(' ');
			}
			b++;
		}
		a++;
	}
}
