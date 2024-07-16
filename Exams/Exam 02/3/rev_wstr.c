/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_wstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 08:55:37 by sde-carv          #+#    #+#             */
/*   Updated: 2024/07/16 09:01:22 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int av, char **args)
{
	int	start;
	int	end;
	int	flag;
	int	i = 0;

	if (av == 2)
	{
		while (args[1][i] == '\0')
			i++;
		while (i >= 0)
		{
			while (args[1][i] == '\0' || args[1][i] == ' ' || args[1][i] == '\t')
				i--;
			end = i;
			while (args[1][i] && args[1][i] != ' ' args[1][i] != '\t')
				i--;
			start = i + 1;
			flag = start;
			while (start <= end)
			{
				write(1, &args[1][start], 1);
				start++;
			}
			if (flag != 0)
				write(1, " ", 1);
		}
	}
	write(1, "\n", 1);
	return (0);
}
