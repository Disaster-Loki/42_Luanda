/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_rest.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 14:16:51 by sde-carv          #+#    #+#             */
/*   Updated: 2024/08/23 14:31:38 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

int	total_collectable(char **map)
{
	int	i;
	int	j;
	int	count;

	i = -1;
	count = 0;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'C')
				count++;
		}
	}
	return (count);
}

char	**dup_map(char **map)
{
	int		i;
	char	**dup_map;

	i = ft_len_line(map);
	dup_map = (char **)malloc(sizeof(char *) * (i + 1));
	i = -1;
	while (map[++i])
		dup_map[i] = ft_strdup(map[i]);
	dup_map[i] = NULL;
	return (dup_map);
}

void	walk_path(char **map, int x, int y, t_point *begin)
{
	if (map[x][y] == '1')
		return ;
	if (map[x][y] == 'F')
		return ;
	if (map[x][y] == begin->ch)
		return ;
	if (map[x][y] == begin->exit)
		begin->count = begin->count + 1;
	map[x][y] = 'F';
	walk_path(map, (x + 1), y, begin);
	walk_path(map, (x - 1), y, begin);
	walk_path(map, x, (y + 1), begin);
	walk_path(map, x, (y - 1), begin);
}
