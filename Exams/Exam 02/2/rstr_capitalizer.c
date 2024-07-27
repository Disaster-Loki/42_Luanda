/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rstr_capitalizer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 08:10:50 by sde-carv          #+#    #+#             */
/*   Updated: 2024/07/23 08:26:30 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	main(int av, char **args)
{
	int	i = 1;
	if (av != 1)
	{
		while (i < av)
		{
			while (*args[i])
			{
				if (*args[i] >= 'A' && *args[i] <= 'Z')
					*args[i] += 32;
				if ((*args[i] >= 'a' && *args[i] <= 'z') && (*(args[i]+1) == ' ' || *(args[i]+1) == '\t' || *(args[i]+1) == '\n' || *(args[i]+1) == '\0'))
					*args[i] -= 32;
				ft_putchar(*args[i]);
				args[i]++;
			}
			ft_putchar('\n');
			i++;
		}
	}
	else
		ft_putchar('\n');
	return (0);
}
