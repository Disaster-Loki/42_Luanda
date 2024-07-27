/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 17:06:57 by sde-carv          #+#    #+#             */
/*   Updated: 2024/07/27 17:06:59 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_hex(int n)
{
	char	digit[] = "0123456789abcdef";
	if (n > 16)
		print_hex(n / 16);
	ft_putchar(digit[n % 16]);
}

int	ft_atoi(char *str)
{
	int res = 0;
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
		print_hex(ft_atoi(args[1]));
	ft_putchar('\n');
	return (0);
}
