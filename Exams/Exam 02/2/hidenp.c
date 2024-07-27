/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hidenp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 16:27:41 by sde-carv          #+#    #+#             */
/*   Updated: 2024/07/27 16:27:44 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	main(int av, char **args)
{
	if (av == 3)
	{
		int	i = 0;
		while (*args[2])
		{
			if (args[1][i] == *args[2])
				i++;
			args[2]++;
		}
		if (args[1][i] == '\0')
			ft_putchar('1');
		else
			ft_putchar('0');
	}
	ft_putchar('\n');
	return (0);
}
