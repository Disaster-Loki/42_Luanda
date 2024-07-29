/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_mult.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 12:58:33 by sde-carv          #+#    #+#             */
/*   Updated: 2024/07/29 12:58:35 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	if (n > 9)
		ft_putnbr(n / 10);
	ft_putchar((n % 10) + '0');
}

int	ft_atoi(char *str)
{
	int	res = 0;
	int	sign = 1;

	while (*str == ' ' || *str == '\t')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
		res = (res * 10) + (*str++ - '0');
	return (res * sign);
}

int	main(int av, char **args)
{
	if (av == 2)
	{
		int	i = 0;
		int	n = ft_atoi(args[1]);
		while (++i <= 9)
		{
			ft_putnbr(i);
			ft_putchar(' ');
			ft_putchar('x');
			ft_putchar(' ');
			ft_putnbr(n);
			ft_putchar(' ');
			ft_putchar('=');
			ft_putchar(' ');
			ft_putnbr(i*n);
			ft_putchar('\n');
		}

	}
	else
		ft_putchar('\n');
	return (0);
}
