/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <sde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 14:49:19 by sde-carv          #+#    #+#             */
/*   Updated: 2024/05/18 17:26:25 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	t_size;

	if (count == 0 || size == 0)
		t_size = 0;
	else
	{
		t_size = count * size;
		if (t_size / size != count)
			return (NULL);
	}
	ptr = malloc(t_size);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, t_size);
	return (ptr);
}
