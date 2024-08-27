/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 14:16:51 by sde-carv          #+#    #+#             */
/*   Updated: 2024/08/23 14:16:55 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

int	check_character(char c)
{
	return ((c == '0') || (c == '1') || (c == 'E') || (c == 'P') || (c == 'C'));
}

int	ft_len_line(char **map)
{
	int	len;

	len = 0;
	while (map[len])
		len++;
	return (len);
}

int	single_character(char *map, char c)
{
	int	ch;
	int	i;

	ch = 0;
	i = -1;
	while (map[++i])
	{
		if (map[i] == c)
			ch++;
		if (ch >= 2)
			return (0);
	}
	if (ch == 0)
		return (-1);
	return (1);
}

t_point	begin_position(char **map, char c)
{
	int		i;
	int		j;
	t_point	pos;

	i = -1;
	pos.x = 0;
	pos.y = 0;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == c)
			{
				pos.x = i;
				pos.y = j;
				return (pos);
			}
		}
	}
	return (pos);
}
