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
			error("Error - Incomplete map\n", 1);
	}
	if (ft_strncmp(map[0], map[i], ft_strlen(map[i])) != 0)
		error("Error - Poorly structured map\n", 1);
	i = 0;
	while (map[++i])
	{
		len = ft_strlen(map[i]);
		if ((map[i][0] != c) || (map[i][len-1] != c))
			error("Error - Poorly structured map\n", 1);
	}
}

int	validate_maps(char **map)
{
	valid_character(map);
	valid_walls_map(map, '1');
	return (1);
}
