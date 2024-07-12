/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 16:30:06 by sde-carv          #+#    #+#             */
/*   Updated: 2024/06/17 16:58:13 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	has(char *str, char c)
{
	while (*str)
	{
		if (*str == c)
			return 1;
		str++;
	}
	return (0);
}

void	inter(char *str, char *str2)
{
	int	i = 0;
	char	printed[128] = {0};

	while (*str)
	{
		if (has(str2, *str) && !has(printed, *str))
		{
			ft_putchar(*str);
			printed[i] = *str;
			i++;
		}
		str++;
	}
}

int	main(int av, char **args)
{
	int	i;

	if (av == 3)
		inter(args[1], args[2]);
	ft_putchar('\n');
	return (0);
}
