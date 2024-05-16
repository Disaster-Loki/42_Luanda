/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 18:32:38 by sde-carv          #+#    #+#             */
/*   Updated: 2023/11/28 19:07:11 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
	{
		i++;
	}
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int		i;
	unsigned int		j;
	unsigned int		d_len;
	unsigned int		s_len;

	i = 0;
	j = 0;
	while (dest[j] != '\0')
	{
		j++;
	}
	d_len = j;
	s_len = ft_strlen(src);
	if (size == 0 || size <= d_len)
		return (s_len + size);
	while (src[i] != '\0' && i < size - d_len -1)
	{
		dest[j] = src[i];
		i++;
		j++;
	}
	dest[j] = '\0';
	return (d_len + s_len);
}
