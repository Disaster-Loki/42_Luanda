/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 13:02:32 by sde-carv          #+#    #+#             */
/*   Updated: 2024/05/14 13:02:35 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*p;

	p = s;
	while (*p != '\0')
		p++;
	while (p >= s){
		if (*p == (char)c)
			return (char *)p;
		p--;
	}
	return (NULL);
}
