/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <sde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 11:35:12 by sde-carv          #+#    #+#             */
/*   Updated: 2024/06/17 10:17:27 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str, char *color)
{
	char	*reset;

	if (color)
	{
		while (*color)
			write(1, color++, 1);
	}
	while (*str)
		write(1, str++, 1);
	if (color)
	{
		reset = COLOR_RESET;
		while (*reset)
			write(1, reset++, 1);
	}
}

void	ft_putnbr(int n)
{
	if (n == -2147483648)
		ft_putstr("-2147483648", LIME);
	else if (n < 0)
	{
		ft_putchar('-');
		ft_putnbr(-n);
	}
	else if (n >= 0 && n <= 9)
		ft_putchar(n + '0');
	else
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
}

int	ft_atoi(char *ptr)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while (ptr[i] && ((ptr[i] >= 9 && ptr[i] <= 13) || ptr[i] == ' '))
		i++;
	if (ptr[i] == '+' || ptr[i] == '-')
	{
		if (ptr[i] == '-')
			sign = -1;
		i++;
	}
	while (ptr[i] && (ptr[i] >= '0' && ptr[i] <= '9'))
	{
		result = (result * 10) + (ptr[i] - '0');
		i++;
	}
	return (result * sign);
}
