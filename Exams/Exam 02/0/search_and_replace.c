/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_and_replace.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 13:28:39 by sde-carv          #+#    #+#             */
/*   Updated: 2024/07/08 13:50:14 by sde-carv         ###   ########.fr       */
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
	if (av == 4 && args[1][i])
	{
		char	from = args[2][0];
		char	to = args[3][0];
		if (((from >= 'a' && from <= 'z') || (from >= 'A' && from <= 'Z')) && args[2][1] == '\0')
		{
			if (((to >= 'a' && to <= 'z') || (to >= 'A' && to <= 'Z')) && args[3][1] == '\0')
			{
				while (args[1][i])
				{
					if (args[1][i] == from)
						args[1][i] = to;
					ft_putchar(args[1][i]);
					i++;
				}
			}
		}
	}
	ft_putchar('\n');
	return (0);
}
