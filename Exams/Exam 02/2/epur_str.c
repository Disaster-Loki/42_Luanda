/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   epur_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 08:13:25 by sde-carv          #+#    #+#             */
/*   Updated: 2024/07/16 08:18:49 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	main(int av, char **args)
{
	int	i;
	int	flg;
	char	*str;

	if (av == 2)
	{
		i = 0;
		flg = 0;
		str = args[1];
		while (str[i] == ' ' || str[i] == '\t')
			i++;
		while (str[i])
		{
			if (str[i] == ' ' || str[i] == '\t')
				flg = 1;
			if (!(str[i] == ' ' || str[i] == '\t'))
			{
				if (flg)
					ft_putchar(' ');
				flg = 0;
				ft_putchar(str[i]);
			}
			i++;
		}
	}
	ft_putchar('\n');
	return (0);
}
