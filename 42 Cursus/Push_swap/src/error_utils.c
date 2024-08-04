/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aux.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 11:13:27 by sde-carv          #+#    #+#             */
/*   Updated: 2024/08/02 11:16:36 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	ft_isdigit_string(char *s)
{
	while (*s)
	{
		if (!ft_isdigit(*s))
			return (0);
		s++;
	}
	return (1);
}

int	is_valid_integer(char *s)
{
	long	num;
	int		sign;

	sign = 1;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	if (!*s)
		return (0);
	num = 0;
	while (*s)
	{
		if (!ft_isdigit(*s))
			return (0);
		num = num * 10 + (*s - '0');
		if (num * sign > INT_MAX || num * sign < INT_MIN)
			return (0);
		s++;
	}
	return (1);
}

int	has_duplicates(char **args)
{
	int	i;
	int	j;

	i = -1;
	while (args[++i])
	{
		j = i + 1;
		while (args[j])
		{
			if (ft_atoi(args[i]) == ft_atoi(args[j]))
				return (1);
			j++;
		}
	}
	return (0);
}
