/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hidenp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 15:47:45 by sde-carv          #+#    #+#             */
/*   Updated: 2024/06/26 16:04:04 by sde-carv         ###   ########.fr       */
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
	int	j = 0;
	char	*s1;
	char	*s2;

	if (av == 3)
	{
		s1 = args[1];
		s2 = args[2];
		while (s1[i] && s2[j])
		{
			if (s1[i] == s2[j])
				i++;
			j++;
		}
		if (s1[i] == '\0')
			ft_putchar('1');
		else
			ft_putchar('0');
	}
	ft_putchar('\n');
	return (1);
}
