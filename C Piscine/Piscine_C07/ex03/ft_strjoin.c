/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 17:31:53 by sde-carv          #+#    #+#             */
/*   Updated: 2023/12/05 17:39:07 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = ft_strlen(dest);
	j = 0;
	while (src[j])
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}

int	ft_length(char **strs, char *sep, int size)
{
	int	i;
	int	aux;

	i = 0;
	aux = 0;
	while (i < size)
	{
		aux += ft_strlen(strs[i]);
		i++;
	}
	aux += ft_strlen(sep) * (size - 1) + 1;
	return (aux);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	char	*aux;

	i = 0;
	if (size == 0)
	{
		aux = malloc(sizeof(char));
		*aux = 0;
		return (aux);
	}
	aux = (char *)malloc(sizeof(char *) * ft_length(strs, sep, size));
	if (!aux)
		return (NULL);
	*aux = 0;
	while (i < size)
	{
		ft_strcat(aux, strs[i]);
		if (i < size - 1)
			ft_strcat(aux, sep);
		i++;
	}
	return (aux);
}
