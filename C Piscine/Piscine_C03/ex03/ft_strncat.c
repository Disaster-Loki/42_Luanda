/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 17:43:24 by sde-carv          #+#    #+#             */
/*   Updated: 2023/11/28 17:54:46 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *desc, char *src, unsigned int nb)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (desc[i] != '\0')
	{
		i++;
	}
	j = 0;
	while (src[j] != '\0' && j < nb)
	{
		desc[i + j] = src[j];
		j++;
	}
	desc[i + j] = '\0';
	return (desc);
}
