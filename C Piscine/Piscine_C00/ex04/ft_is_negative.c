/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 09:17:45 by sde-carv          #+#    #+#             */
/*   Updated: 2023/11/17 09:28:40 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	print_number(char c)
{
	write(1, &c, 1);
}

void	ft_is_negative(int a)
{
	if (a >= 0)
	{
		print_number('P');
	}
	else
	{
		print_number('N');
	}
}
