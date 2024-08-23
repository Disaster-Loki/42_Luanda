#include "../../inc/so_long.h"

int total_collectable(char **map)
{
    int i;
    int j;
    int count;

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

void	walk_path(char **map, int x, int y, t_point *begin)
{
	if (map[x][y] == '1')
		return ;
	if (map[x][y] == 'F')
		return ;
	if (map[x][y] == begin->ch)
		return ;
	if (map[x][y] == 'C')
		begin->found = begin->found + 1;
	map[x][y] = 'F';
	walk_path(map, (x + 1), y, begin);
	walk_path(map, (x - 1), y, begin);
	walk_path(map, x, (y + 1), begin);
	walk_path(map, x, (y - 1), begin);
}

char    **dup_map(char **map)
{
    int     i;
    int     x;
    int     y;
    char    **map_clone;

    if (!(*map) || !map)
        return (NULL);
    i = ft_len_line(map);
    map_clone = (char **)malloc(sizeof(char *) * (i + 1));
    x = -1;
    while (map[++x])
    {
        y = -1;
        map_clone[x] = ft_strdup(map[x]);
        while (map[x][++y])
            map_clone[x][y] = map[x][y];
        map_clone[x][y] = '\0';
    }
    map_clone[x] = NULL;
    return (map_clone);
}
