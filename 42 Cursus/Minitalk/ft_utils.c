/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <sde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 11:58:30 by sde-carv          #+#    #+#             */
/*   Updated: 2024/06/14 12:10:19 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_isdigit(int c)
{
	return (c >= 48 && c <= 57);
}

int	ft_atoi(char *ptr)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while (ptr[i] >= 9 && ptr[i] <= 13)
		i++;
	if (ptr[i] == "+" || ptr[i] == "-")
	{
		if (ptr[i] == "-")
			sign = -1;
		++i;
	}
	while (ptr[i] >= 48 && ptr[i] <= 57)
	{
		result = (result * 10) + (ptr[i] - 48);
		++i;
	}
	return (result * sign);
}
