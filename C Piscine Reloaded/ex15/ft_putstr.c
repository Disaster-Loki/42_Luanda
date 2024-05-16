/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 11:27:59 by sde-carv          #+#    #+#             */
/*   Updated: 2024/05/06 11:49:59 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putchar(char c);

void	ft_putstr(char *str)
{
	int	aux;

	aux = 0;
	while (str[aux])
	{
		ft_putchar(str[aux]);
		aux += 1;
	}
}
