/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_prime_sum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 13:31:20 by sde-carv          #+#    #+#             */
/*   Updated: 2024/07/27 13:31:24 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	isPrime(int n)
{
	int	i = 2;
	if (n <= 1)
		return (0);
	while (i * i <= n)
	{
		if (n % i == 0)
			return  (0);
		i++;
	}
	return (1);
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
	int	i;
	int	sum;

	if (av == 2)
	{
		i = 2;
		sum = 0;
		int	num = ft_atoi(args[1]);
		while (i <= num)
		{
			if(isPrime(i))
				sum += i;
			i++;
		}
		ft_putnbr(sum);
	}
	else
		ft_putnbr(0);
	ft_putchar('\n');
	return (0);
}
