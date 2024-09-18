/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 10:34:18 by sde-carv          #+#    #+#             */
/*   Updated: 2024/09/15 10:34:47 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

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
		reset = RESET;
		while (*reset)
			write(1, reset++, 1);
	}
}

int	ft_atoi(char *str)
{
	int	sig;
	int	res;

	sig = 1;
	res = 0;
	while (*str >= 9 && *str <= 13)
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sig = -1;
	}
	while (*str >= '0' && *str <= '9')
		res = (res * 10) + (*str++ - '0');
	return (res * sig);
}
