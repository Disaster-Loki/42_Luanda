/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 13:22:55 by sde-carv          #+#    #+#             */
/*   Updated: 2023/11/29 13:23:21 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print(char c)
{
	write(1, &c, 1);
}

void	ft_convert_hexa(unsigned char c)
{
	char	*hexa;

	hexa = "0123456789abcdef";
	if (c / 16 > 0)
	{
		print(hexa[c / 16]);
		print(hexa[c % 16]);
	}
	else
	{
		print('0');
		print(hexa[c]);
	}
}

void	ft_putstr_non_printable(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < 32 || str[i] > 126)
		{
			print('\\');
			ft_convert_hexa(str[i]);
		}
		else
		{
			print(str[i]);
		}
		i++;
	}
}
