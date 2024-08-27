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

void	valid_character(char **map)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (!check_character(map[i][j]))
				error_map("Error -Invalid character!!\n", map);
		}
	}
}

void	valid_walls_map(char **map, char c)
{
	int	i;
	int	len;

	i = -1;
	if (ft_len_line(map) < 3)
		error_map("Error - Poorly structured map !!\n", map);
	len = (int) ft_strlen(map[0]);
	while (map[++i] && map[i + 1])
	{
		if (len != (int) ft_strlen(map[i + 1]))
			error_map("Error - Poorly structured map !!\n", map);
	}
	if (ft_strncmp(map[0], map[i], ft_strlen(map[i])) != 0)
		error_map("Error - Poorly structured map !!\n", map);
	i = 0;
	while (map[++i])
	{
		len = (int) ft_strlen(map[i]);
		if ((map[i][0] != c) || (map[i][len - 1] != c))
			error_map("Error - Poorly structured map !!\n", map);
	}
}

void	valid_path_map(char **map, int c, char s, char e)
{
	t_point	begin;
	int		t_collectable;

	t_collectable = total_collectable(map);
	begin = begin_position(map, s);
	begin.ch = c;
	begin.exit = e;
	begin.count = 0;
	walk_path(map, begin.x, begin.y, &begin);
	if (e == 'C')
	{
		if (t_collectable != begin.count)
			error_map("Error - No path to the collectible !!\n", map);
	}
	else if (e == 'E')
		if (!begin.count)
			error_map("Error - No way out\n", map);
}

int	validate_maps(char **map)
{
	char	**copy;
	char	**copy2;

	copy = map;
	copy2 = map;
	valid_character(map);
	valid_walls_map(map, '1');
	valid_path_map(copy2, 'S', 'P', 'E');
	valid_path_map(copy, 'E', 'P', 'C');
	return (1);
}
