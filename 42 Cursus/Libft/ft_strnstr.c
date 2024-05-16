/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 13:03:29 by sde-carv          #+#    #+#             */
/*   Updated: 2024/05/14 13:03:31 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	const char	*p1;
	const char	*p2;
	const char	*temp;

	p1 = big;
	p2 = little;
	while (*p1 != '\0' && len > 0)
	{
		temp = p1;
		while (*p2 != '\0' && *temp == *p2 && len > 0)
		{
			temp++;
			p2++;
			len--;
		}
		if (*p2 == '\0')
			return ((char *)p1);
		p1++;
		len--;
	}
	return (NULL);
}
