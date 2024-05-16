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

void	rush(char *dict, char *num)
{
	char	*buffer;

	buffer = ft_open_read(dict);
	if (!buffer)
	{
		free(buffer);
		return ;
	}
	print_all(buffer, num);
	free(buffer);
}
