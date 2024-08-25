/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 10:30:25 by sde-carv          #+#    #+#             */
/*   Updated: 2024/08/25 10:30:28 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	print_map(char **map)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
			write(1, &map[i][j], 1);
		write(1, "\n", 1);
	}
}

char	**get_map(char *str)
{
	int		fd;
	int		size;
	char	*buffer;
	char	**map;

	fd = open(str, O_RDONLY);
	buffer = (char *)malloc(sizeof(char) * 1024);
	size = read(fd, buffer, 1024);
	buffer[size] = '\0';
	map = ft_split(buffer, '\n');
	return (map);
}
