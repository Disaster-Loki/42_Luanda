/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 08:21:38 by sde-carv          #+#    #+#             */
/*   Updated: 2024/07/09 08:21:43 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include <stdlib.h>

char	**ft_split(char *str)
{
	int	i = 0;
	int	len = 0;
	int	f;
	char	**result;

	while (str[len])
		len++;
	while (*str == ' ' || *str == '\t')
		str++;
	result = (char **)malloc(sizeof(char *) * (len + 1));
	if (!result)
		return (NULL);
	while (*str)
	{
		f = 0;
		result[i] = (char *)malloc(sizeof(char) * (len + 1));
		while (*str != ' ' && *str != '\t' && *str)
			result[i][f++] = *(str++);
		while (*str == ' ' || *str == '\t')
			str++;
		result[i++][f] = '\0';
	}
	result[i] = NULL;
	return (result);
}

