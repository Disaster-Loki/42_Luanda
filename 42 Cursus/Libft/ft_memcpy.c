/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <sde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 12:58:32 by sde-carv          #+#    #+#             */
/*   Updated: 2024/05/16 17:33:46 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	void	*aux;

	if (dest == NULL || src == NULL)
		return (NULL);
	aux = dest;
	while (n--)
		*(unsigned char *)dest = *(unsigned char *)src;
	return (aux);
}
