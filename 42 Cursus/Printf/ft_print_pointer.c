/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <sde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 15:15:38 by sde-carv          #+#    #+#             */
/*   Updated: 2024/05/19 17:20:18 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static char	*create_string(unsigned long value, int *len)
{
	int				i;
	unsigned long	temp;
	char			*str;

	i = 0;
	temp = value;
	while (temp != 0)
	{
		temp = temp / 16;
		i++;
	}
	str = ft_calloc(i + 1, sizeof(char));
	*len = i - 1;
	return (str);
}

int	print_pointer(unsigned long value, int asc)
{
	unsigned long	tempval;
	char			*printout;
	int				i;
	int				*iptr;

	iptr = &i;
	tempval = value;
	printout = create_string(value, iptr);
	if (!printout)
		return (0);
	while (tempval != 0 && i-- >= 0)
	{
		if ((tempval % 16) < 10)
			printout[i + 1] = (tempval % 16) + 48;
		else
			printout[i + 1] = (tempval % 16) + asc;
		tempval = tempval / 16;
	}
	i = ft_strlen(printout);
	i = i + print_string("0x");
	ft_putstr_fd(printout, 1);
	free(printout);
	if (value == 0)
		i += print_char('0');
	return (i);
}
