/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pgcd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 16:03:46 by sde-carv          #+#    #+#             */
/*   Updated: 2024/06/14 16:37:38 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int static	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] >= 9 && str[i] <= 13)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		result = (result * 10) + (str[i] - '0');
		++i;
	}
	return (result * sign);
}

int	main(int av, char **args)
{
	int	i;
	int	count;
	char	num;

	i = 1;
	if (av == 3)
	{
		while (i <= ft_atoi(args[1]) || i <= ft_atoi(args[2]))
		{
			if ((ft_atoi(args[1]) % i == 0) && (ft_atoi(args[2]) % i == 0))
				count = i;
			i++;
		}
		num = count + '0';
		write(1, &num, 1);
	}
	write(1, "\n", 1);
	return (0);
}
