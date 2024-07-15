/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 16:40:12 by sde-carv          #+#    #+#             */
/*   Updated: 2024/07/15 16:40:16 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int av, char **args)
{
	if (av == 3)
	{
		int ascii[255] = {0};
		int	i = 1, j = 0;
		while (i < 3)
		{
			j = 0;
			while (args[i][j])
			{
				if (ascii[(int)args[i][j]] == 0)
				{
					ascii[(int)args[i][j]] = 1;
					write(1, &args[i][j], 1);
				}
				j++;
			}
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}

