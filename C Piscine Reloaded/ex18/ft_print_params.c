/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 11:38:22 by sde-carv          #+#    #+#             */
/*   Updated: 2024/05/07 11:55:14 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

int	main(int argc, char *argv[])
{
	int	column;

	argc = 1;
	while (argv[argc])
	{
		column = 0;
		while (argv[argc][column])
		{
			ft_putchar(argv[argc][column]);
			column++;
		}
		ft_putchar('\n');
		argc++;
	}
	return (0);
}
