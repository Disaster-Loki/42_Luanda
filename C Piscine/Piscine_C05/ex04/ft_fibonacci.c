/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 18:30:38 by sde-carv          #+#    #+#             */
/*   Updated: 2023/12/04 18:30:43 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_fibonacci(int index)
{
	int	aux;

	aux = 1;
	if (index < 2)
		return (index);
	if (index < 0)
		return (-1);
	else
		aux = (ft_fibonacci(index - 1) + ft_fibonacci(index - 2));
	return (aux);
}
