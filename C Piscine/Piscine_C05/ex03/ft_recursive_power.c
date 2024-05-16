/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 18:07:55 by sde-carv          #+#    #+#             */
/*   Updated: 2023/12/04 18:08:01 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_power(int nb, int power)
{
	int	aux;

	aux = 1;
	if ((power != 0 && nb == 0) || power < 0)
		return (0);
	else if ((nb < 0 && power == 0) || power == 0)
		return (1);
	else
		aux = (nb * ft_recursive_power(nb, power - 1));
	return (aux);
}
