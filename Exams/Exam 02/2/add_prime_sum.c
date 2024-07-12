/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_prime_sum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 14:02:55 by sde-carv          #+#    #+#             */
/*   Updated: 2024/07/11 14:25:57 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	isPrime(int num)
{
	int	i = 2;
	if (num <= 1)
		return (0);
	while (i * i <= num)
	{
		if (num % i == 0)
			return (0);
		i++;
	}
	return (1);
}

void	ft_putnbr(int	n)
{
	if (n > 9)
		ft_putnbr(n / 10);
	ft_putchar((n % 10) + '0');
}

int	ft_atoi(char *str)
{
	int	i = 0;
	int	sign = 1;
	int	result = 0;

	while (*str == ' ' || *str == '\t')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = (result * 10) + (*str - '0');
		str++;
	}
	return (result * sign);
}

int	main(int argc, char **argv)
{
	int	num;
	int	sum;
	int	i;

	if (argc == 2 && *argv[1])
	{
		num = ft_atoi(argv[1]);
		sum = 0;
		i = 2;
		while (i <= num)
		{
			if (isPrime(i))
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
