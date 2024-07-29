/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_wstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 14:28:04 by sde-carv          #+#    #+#             */
/*   Updated: 2024/07/29 14:28:07 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	main(int av, char **args)
{
	if (av == 2)
	{
		int	i = 0;
		int	flg = 0;
		int	end = 0;
		int	start = 0;

		while (args[1][i])
			i++;
		while (i >= 0)
		{
			while (args[1][i] == '\0' || args[1][i] == ' ' || args[1][i] == '\t')
				i--;
			end = i;
			while (args[1][i] && args[1][i] != ' ' && args[1][i] != '\t')
				i--;
			start = i + 1;
			flg = start;
			while (start <= end)
				ft_putchar(args[1][start++]);
			if(flg)
				ft_putchar(' ');
		}
	}
	ft_putchar('\n');
	return (0);
}


