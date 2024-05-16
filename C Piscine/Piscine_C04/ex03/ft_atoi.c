/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 11:35:57 by sde-carv          #+#    #+#             */
/*   Updated: 2023/11/30 13:13:36 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	whitespace(char *str, int *result)
{
	int	i;
	int	count;

	i = 0;
	count = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
	{
		i++;
	}
	while (str[i] == 43 || str[i] == 45)
	{
		if (str[i] == 45)
		{
			count *= -1;
		}
		i++;
	}
	*result = i;
	return (count);
}

int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	result;

	sign = whitespace(str, &i);
	result = 0;
	while (str[i] && str[i] >= 48 && str[i] <= 57)
	{
		result *= 10;
		result += str[i] - 48;
		i++;
	}
	result *= sign;
	return (result);
}
