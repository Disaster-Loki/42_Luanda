/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 15:30:25 by sde-carv          #+#    #+#             */
/*   Updated: 2024/07/11 15:44:40 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char    *ft_strdup(char *src)
{
	int		i = 0;
	char	*new;
	
	while (src[i])
		i++;
	new = malloc(sizeof(char) * (i + 1));
	i = 0;
	while (src[i])
	{
		new[i] = src[i];
		i++;	
	}
	new[i] = '\0';
	return (new);
}
