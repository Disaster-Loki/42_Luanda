/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 14:20:40 by sde-carv          #+#    #+#             */
/*   Updated: 2024/05/07 14:29:19 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	i;
	int	length;
	int	*array;

	i = 0;
	if (min >= max)
		return (NULL);
	length = max - min;
	array = malloc(sizeof(int) * length);
	if (!length)
		return (0);
	while (length > 0)
	{
		array[i] = min;
		min++;
		i++;
		length--;
	}
	return (array);
}
