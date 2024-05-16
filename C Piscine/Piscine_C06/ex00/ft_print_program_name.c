/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 07:55:45 by sde-carv          #+#    #+#             */
/*   Updated: 2023/12/05 07:55:51 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print(char c)
{
	write(1, &c, 1);
}

int	main(int av, char *args[])
{
	int	aux;

	aux = 0;
	while (args[0][aux] != '\0')
	{
		print(args[0][aux]);
		aux++;
	}
	print('\n');
	return (0);
}
