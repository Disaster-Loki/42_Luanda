/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrange.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 16:13:37 by sde-carv          #+#    #+#             */
/*   Updated: 2024/07/27 16:13:39 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

int	*ft_rrange(int start, int end)
{
	int	*res;
	int i = 0;
	int	len = ft_abs(end - start) + 1;
	res = malloc(sizeof(int) * len);
	while (i < len)
	{
		res[i++] = end;
		if (end < start)
			end++;
		else
			end--;
	}
	return (res);
}
