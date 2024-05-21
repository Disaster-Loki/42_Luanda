/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 13:02:17 by sde-carv          #+#    #+#             */
/*   Updated: 2024/05/14 13:02:20 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int n)
{
	int				i;
	unsigned char	aux;

	i = 0;
	aux = (unsigned char)n;
	while (s[i])
	{
		if (s[i] == aux)
			return ((char *)&s[i]);
		i++;
	}
	if (aux == '\0')
		return ((char *)&s[i]);
	return (NULL);
}
