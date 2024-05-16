/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 19:08:13 by sde-carv          #+#    #+#             */
/*   Updated: 2023/12/04 19:08:17 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int	ft_sqrt(int nb)
{
	int	aux;
	int	sqrt;

	aux = 1;
	sqrt = 1;
	if (nb == 0)
		return (nb);
	while (aux * aux < nb)
		aux++;
	if ((nb % aux) == 0)
		return (aux);
	else
		return (0);
}

int	main(void)
{
	printf("%d\n", ft_sqrt(64));
}
