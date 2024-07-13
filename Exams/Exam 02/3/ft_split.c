/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 15:00:35 by sde-carv          #+#    #+#             */
/*   Updated: 2024/07/13 15:00:38 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

char    **ft_split(char *str)
{
	int		i = 0;
	int		len = 0;
	int		col = 0;
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
		col = 0;
		result[i] = (char *)malloc(sizeof(char) * (len + 1));
		while (*str && *str != ' ' && *str != '\t')
			result[i][col++] = *(str++);
		while (*str == ' ' || *str == '\t')
			str++;
		result[i++][col] = '\0';
	}
	result[i] = NULL;
	return (result);
}

