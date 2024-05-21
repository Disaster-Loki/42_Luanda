/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <sde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 14:26:44 by sde-carv          #+#    #+#             */
/*   Updated: 2024/05/17 14:45:05 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*new;

	len = ft_strlen(s);
	new = malloc((sizeof(char) * (len + 1)));
	if (!new)
		return (0);
	ft_strlcpy(new, s, (len + 1));
	return (new);
}
