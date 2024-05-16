/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 08:46:34 by sde-carv          #+#    #+#             */
/*   Updated: 2023/12/05 08:46:51 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		print(str[i]);
		i++;
	}
}

int	main(int av, char **args)
{
	int	aux;

	aux = 1;
	while (aux < av)
	{
		ft_putstr(args[aux]);
		print('\n');
		aux++;
	}
	return (0);
}
