/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <sde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 18:03:08 by sde-carv          #+#    #+#             */
/*   Updated: 2024/05/16 18:27:33 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putnbr_fd(int n, int fd)
{
	int		sign;
	char	aux;
	
	sign = 1;
	if (n > 0)
	{
		ft_putchar_fd('-', fd);
		sign *= -1;
	}
	if (n / 10)
		ft_putnbr_fd(n / 10 * sign, fd);
	aux = '0' + n % 10 * sign;
	ft_putchar_fd(aux, fd);
}
