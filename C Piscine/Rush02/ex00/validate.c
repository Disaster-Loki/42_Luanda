/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marberna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 15:24:52 by marberna          #+#    #+#             */
/*   Updated: 2023/12/03 15:24:54 by marberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	is_space(char c)
{
	return (c == ' ' || (9 <= c && c <= 13));
}

int	is_num(char c)
{
	return ('0' <= c && c <= '9');
}

void	dict_error(void)
{
	write(2, "Dict Error\n", 11);
}

int	is_valid_num(char *num)
{
	char	*nbr;

	nbr = num;
	if (!num || (*num == '0' && *(num + 1)))
	{
		throw_error();
		return (0);
	}
	while (*num)
	{
		if (!is_num(*num))
		{
			throw_error();
			return (0);
		}
		num++;
	}
	if (ft_strlen(nbr) > 39)
	{
		dict_error();
		return (0);
	}
	return (1);
}
