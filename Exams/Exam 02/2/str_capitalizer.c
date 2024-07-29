/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_capitalizer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 12:44:39 by sde-carv          #+#    #+#             */
/*   Updated: 2024/07/29 12:44:42 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	main(int av, char **args)
{
	if (av > 1)
	{
		int	i = 0;
		while (++i < av)
		{
			while (*args[i])
			{
				while (*args[i] && (*args[i] == ' ' || *args[i] == '\t'))
					ft_putchar(*args[i]++);
				if (*args[i])
				{
					if (*args[i] >= 'a' && *args[i] <= 'z')
						*args[i] -= ('a' - 'A');
					ft_putchar(*args[i]++);
				}
				while (*args[i] && *args[i] != ' ' && *args[i] != '\t')
				{
					if (*args[i] >= 'A' && *args[i] <= 'Z')
						*args[i] += ('a' - 'A');
					ft_putchar(*args[i]++);
				}
			}
			ft_putchar('\n');
		}
	}
	else
		ft_putchar('\n');
	return (0);
}
