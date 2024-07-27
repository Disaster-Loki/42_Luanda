/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 15:25:26 by sde-carv          #+#    #+#             */
/*   Updated: 2024/07/27 15:25:29 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	is_blank(char c)
{
	if (c <= 32)
		return (1);
	return (0);
}

int	isvalid(char c, int base)
{
	char	digit[17] = "0123456789abcdef";
	char	digits[17] = "0123456789ABCDEF";

	while (base--)
		if (digit[base] == c || digits[base] == c)
			return (1);
	return (0);
}

int	value_of(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	else if (c >= 'a' && c <= 'f')
		return (c - 'a' + 10);
	else if (c >= 'A' && c <= 'F')
		return (c - 'A' + 10);
	return (0);
}

int	ft_atoi_base(const char *str, int str_base)
{
	int	sign = 1;
	int res = 0;
	while (is_blank(*str))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (isvalid(*str, str_base))
		res = (res * str_base) + value_of(*str++);
	return (res * sign);
}


int	main(void)
{
	printf("%i\n", ft_atoi_base("1011011011111001", 2));
	return (0);
}