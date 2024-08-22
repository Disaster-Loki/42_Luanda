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

int	single_character(char *map, char c)
{
	int	ch;

	ch = 0;
	while (*map)
	{
		if (*map == c)
			ch++;
		if (ch >= 2)
				return (0);
		map++;
	}
	return (1);
}

void	walk_path(char **map, t_point begin, char ch, int found)
{
	if (map[begin.y][begin.x] == '1')
		return ;
	if (begin.y < 0 || begin.x < 0 || map[begin.y][begin.x] != ch)
		return ;
	if (map[begin.y][begin.x] == 'P')
	{
		found = 1;
		return ;
	}
	map[begin.y][begin.x] = 'F';
	walk_path(map, (t_point){begin.x + 1, begin.y}, ch, found);
	walk_path(map, (t_point){begin.x - 1, begin.y}, ch, found);
	walk_path(map, (t_point){begin.x, begin.y + 1}, ch, found);
	walk_path(map, (t_point){begin.x, begin.y - 1}, ch, found);
}