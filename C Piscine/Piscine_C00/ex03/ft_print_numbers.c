/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 09:25:14 by sde-carv          #+#    #+#             */
/*   Updated: 2023/11/19 09:26:34 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_number(char c)
{
	write(1, &c, 1);
}

void	ft_print_numbers(void)
{
	int	num;

	num = 0;
	while (num <= 9)
	{
		print_number(num + '0');
		num++;
	}
}
