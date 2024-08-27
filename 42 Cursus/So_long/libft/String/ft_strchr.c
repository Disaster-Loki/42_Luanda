/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_minilibx.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 13:29:07 by sde-carv          #+#    #+#             */
/*   Updated: 2024/08/19 13:29:09 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

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
