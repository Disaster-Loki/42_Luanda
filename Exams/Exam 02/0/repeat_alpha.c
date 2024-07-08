/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 12:16:22 by sde-carv          #+#    #+#             */
/*   Updated: 2024/07/08 12:28:40 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	main(int av, char **args)
{
	int	i = 0;
	int	k = 1;
	while (av == 2 && args[1][i])
	{
		k = 1;
		if (args[1][i] >= 'A' && args[1][i] <= 'Z')
			k = args[1][i] - 64;
		if (args[1][i] >= 'a' && args[1][i] <= 'z')
			k = args[1][i] - 96;
		while (k >= 1)
		{
			ft_putchar(args[1][i]);
			k--;
		}
		i++;
	}
	ft_putchar('\n');
	return (0);
}
