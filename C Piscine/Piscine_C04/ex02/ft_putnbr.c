/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 13:33:46 by sde-carv          #+#    #+#             */
/*   Updated: 2023/12/04 13:33:57 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print(char c)
{
	write(1, &c, 1);
}

void	print_max(void)
{
	print('-');
	print('2');
	print('1');
	print('4');
	print('7');
	print('4');
	print('8');
	print('3');
	print('6');
	print('4');
	print('8');
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		print_max();
	}
	else if (nb < 0)
	{
		nb *= -1;
		print('-');
		ft_putnbr(nb);
	}
	else if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
	{
		print(nb + '0');
	}
}
