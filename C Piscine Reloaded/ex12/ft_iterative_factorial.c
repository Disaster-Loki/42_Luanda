/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 15:36:42 by sde-carv          #+#    #+#             */
/*   Updated: 2024/05/06 15:56:46 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	result;

	result = nb;
	if ((nb < 0) || (nb >= 13))
		return (0);
	else if ((nb == 0) || (nb == 1))
		return (1);
	else if (nb > 0)
	{
		nb--;
		while (nb > 0)
		{
			result *= nb;
			nb--;
		}
	}
	return (result);
}
