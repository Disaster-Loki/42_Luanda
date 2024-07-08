/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 10:53:19 by sde-carv          #+#    #+#             */
/*   Updated: 2024/07/08 11:12:59 by sde-carv         ###   ########.fr       */
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
	if (av == 2)
	{
		while (*args[1] == ' ' || *args[1] == '\t')
			args[1]++;
		while (*args[1] && (*args[1] != ' ' && *args[1] != '\t'))
		{
			ft_putchar(*args[1]);
			args[1]++;
		}
	}
	ft_putchar('\n');
	return (0);
}
