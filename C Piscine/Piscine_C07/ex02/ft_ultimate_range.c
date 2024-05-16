/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 16:26:23 by sde-carv          #+#    #+#             */
/*   Updated: 2023/12/05 16:26:47 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	length;

	i = 0;
	length = max - min;
	if (max <= min)
		return (0);
	if (length <= 0)
	{
		*range = NULL;
		return (0);
	}
	if (!*range)
		return (-1);
	*range = (int *)malloc(sizeof(int) * length);
	while (min < max)
	{
		(*range)[i] = min;
		min++;
		i++;
	}
	//return (length);
}
