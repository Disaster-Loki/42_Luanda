/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 17:35:41 by sde-carv          #+#    #+#             */
/*   Updated: 2023/12/04 17:35:50 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	aux;

	aux = 1;
	if ((nb == 0 && power != 0) || power < 0)
		return (0);
	else if ((power == 0) || (nb < 0 && power == 0))
		return (1);
	else
	{
		while (power > 0)
		{
			aux *= nb;
			power--;
		}
	}
	return (aux);
}
