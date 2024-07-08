/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 17:07:36 by sde-carv          #+#    #+#             */
/*   Updated: 2024/07/08 18:05:37 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_numlen(int num)
{
	int	i;

	if (num == 0)
		return (1);
	if (num < 0)
		num = -num;
	i = 0;
	while (num > 0)
	{
		num /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int nbr)
{
	int	len;
	char	*ptr;
	long	n;

	n = nbr;
	len = ft_numlen(n);
	if (n < 0)
	{
		len++;
		n = -n;
	}
	ptr = (char *)malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (NULL);
	ptr[len] = '\0';
	while (n > 0)
	{
		ptr[--len] = (n % 10) + '0';
		n /= 10;
	}
	if (nbr < 0)
		ptr[0] = '-';
	if (nbr == 0)
		ptr[0] = '0';
	return (ptr);
}
