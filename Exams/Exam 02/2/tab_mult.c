/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_mult.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 14:17:15 by sde-carv          #+#    #+#             */
/*   Updated: 2024/07/04 15:15:23 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int n)
{
	char	ch;
	if (n > 9)
		ft_putnbr(n / 10);
	ch = (n % 10) + '0';
	write(1, &ch, 1);
}

int	ft_atoi(char *str)
{
	int	i = -1;
	int	res = 0;
	while (str[++i] >= '0' && str[i] <= '9')
		res = (res * 10) + (str[i] - '0');
       return (res);	
}

int	main(int av, char **args)
{
	int	i = 1;
	int	n;

	while (av == 2 && i <= 9)
	{
		n = ft_atoi(args[1]);
		ft_putnbr(i);
		write(1, " x ", 3);
		ft_putnbr(n);
		write(1, " = ", 3);
		ft_putnbr(i * n);
		write(1, "\n", 1);
		i++;
	}
	if (i == 1)
		write(1, "\n", 1);
	
	return (0);
}
