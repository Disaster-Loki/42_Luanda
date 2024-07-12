/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paramsum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 20:37:12 by sde-carv          #+#    #+#             */
/*   Updated: 2024/06/27 21:04:25 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	main(int av, char **args)
{
	int	i, j;
	char 	str[20];
	
	i = av - 1;
	if (i > 9)
	{
		j = 0;
		while (i != 0)
		{
			str[j++] = (i % 10) + '0';
			i /= 10;
		}
		while (j--)
			ft_putchar(str[j]);
	}
	else
		ft_putchar(i + '0');
	ft_putchar('\n');
	return (0);
}
