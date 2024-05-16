/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 13:17:14 by sde-carv          #+#    #+#             */
/*   Updated: 2023/11/29 13:17:20 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	j;
	int	word;

	word = 1;
	i = 0;
	while (str[i] != '\0')
	{
		j = str[i];
		if (word == 1 && j >= 'a' && j <= 'z')
			str[i] -= 32;
		else if (word == 0 && j >= 'A' && j <= 'Z')
			str[i] += 32;
		if (j < '0' || (j > '9' && j < 'A') || (j > 'Z' && j < 'a') || j > 'z')
			word = 1;
		else
			word = 0;
		i++;
	}
	return (str);
}
