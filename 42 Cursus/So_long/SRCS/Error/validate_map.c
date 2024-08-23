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
				error("Error - Invalid character\n", 1);
		}
	}
}

void	valid_walls_map(char **map, char c)
{
	int	i;
	int	len;

	i = -1;
	len = (int) ft_strlen(map[0]);
	while (map[++i] && map[i + 1])
	{
		if (len != (int) ft_strlen(map[i + 1]))
			error("Error - Poorly formatted map\n", 1);
	}
	if (ft_strncmp(map[0], map[i], ft_strlen(map[i])) != 0)
		error("Error - Poorly structured map\n", 1);
	i = 0;
	while (map[++i])
	{
		len = ft_strlen(map[i]);
		if ((map[i][0] != c) || (map[i][len - 1] != c))
			error("Error - Poorly structured map\n", 1);
	}
}

void	valid_path_map(char **map)
{
	int	i;
	int	j;
	int	len;

	i = -1;
	while (map[++i])
	{
		j = -1;
		len = (int) ft_strlen(map[i]);
		while (map[i][++j])
		{
			if (map[i][j] == 'P' && i > 0 && j < len)
			{
				if ((map[i + 1][j] == '1') && (map[i - 1][j] == '1') &&
				(map[i][j + 1] == '1') && (map[i][j - 1] == '1'))
					error("Error - No path to player\n", 1);
			}
			if (map[i][j] == 'E' && i > 0 && j < len)
			{
				if ((map[i + 1][j] == '1') && (map[i - 1][j] == '1') &&
				(map[i][j + 1] == '1') && (map[i][j - 1] == '1'))
					error("Error - No way out\n", 1);
			}
		}
	}
}

//printf("%d\n%d\n", t_collectable, begin.found);
void	valid_path(char **map, int c, char s)
{
	t_point	begin;
	int		t_collectable;

	t_collectable = total_collectable(map);
	begin = begin_position(map, s);
	begin.ch = c;
	begin.found = 0;
	walk_path(map, begin.x, begin.y, &begin);
	if (t_collectable != begin.found)
		error("Error - No path to the collectible\n", 1);
}

//valid_path(map, 's', 'E');
int	validate_maps(char **map)
{
	char	**copy;

	copy = map;
	valid_character(map);
	valid_walls_map(map, '1');
	valid_path_map(map);
	valid_path(copy, 'E', 'P');
	return (1);
}
