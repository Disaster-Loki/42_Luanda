/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alpha_mirror.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 14:28:26 by sde-carv          #+#    #+#             */
/*   Updated: 2024/07/08 14:43:18 by sde-carv         ###   ########.fr       */
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
	while (av == 2 && args[1][i])
	{
		if (args[1][i] >= 'a' && args[1][i] <= 'z')
			args[1][i] = 219 - args[1][i];
		else if (args[1][i] >= 'A' && args[1][i] <= 'Z')
			args[1][i] = 155 - args[1][i];
		ft_putchar(args[1][i]);
		i++;
	}
	ft_putchar('\n');
	return (0);
}
