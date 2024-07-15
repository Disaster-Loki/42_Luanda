/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_capitalizer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 14:09:14 by sde-carv          #+#    #+#             */
/*   Updated: 2024/07/03 15:06:54 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	str_capitalizer(char *str)
{
	int	i = 0;
	while(str[i])
	{
		while (str[i] && (str[i] == ' ' || str[i] == '\t'))
		{
			write(1, &str[i], 1);
			i++;
		}
		if (str[i])
		{
			if (str[i] >= 'a' && str[i] <= 'z')
				str[i] -= ('a' - 'A');
			write(1, &str[i], 1);
			i++;
		}
		while (str[i] && str[i] != ' ' && str[i] != '\t')
		{
			if (str[i] >= 'A' && str[i] <= 'Z')
				str[i] += ('a' - 'A');
			write(1, &str[i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
}

int	main(int av, char **args)
{
	int	i = 1;
	if (av == 1)
		write(1, "\n", 1);
	while (i < av)
		str_capitalizer(args[i++]);
	return (0);
}
