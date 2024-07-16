/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_bits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 08:02:20 by sde-carv          #+#    #+#             */
/*   Updated: 2024/07/16 08:04:40 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned char	reverse_bits(unsigned char octet)
{
	int	i = 8;
	unsigned char	res = 0;

	while (i > 0)
	{
		res = (res * 2) + (octet % 2);
		octet /= 2;
		i--;
	}
	return (res);
}
