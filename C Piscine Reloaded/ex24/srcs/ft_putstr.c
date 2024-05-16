/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 15:22:19 by sde-carv          #+#    #+#             */
/*   Updated: 2024/05/08 15:22:28 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	print(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	aux;

	aux = 0;
	while (str[aux])
	{
		print(str[aux]);
		aux += 1;
	}
}
