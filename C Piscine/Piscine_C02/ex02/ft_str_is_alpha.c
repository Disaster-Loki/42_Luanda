/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 12:10:10 by sde-carv          #+#    #+#             */
/*   Updated: 2023/11/27 13:35:11 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdio.h>

int	ft_str_is_alpha(char *str)
{
	int	aux;

	aux = 0;
	while (str[aux] != '\0')
	{
		if ((str[aux] >= 'a' && str[aux] <= 'z')
			|| (str[aux] >= 'A' && str[aux] <= 'Z'))
		{
			aux++;
		}
		else
		{
			return (0);
		}
	}
	while (str[aux] == '\0')
	{
		return (1);
	}
	return (1);
}
