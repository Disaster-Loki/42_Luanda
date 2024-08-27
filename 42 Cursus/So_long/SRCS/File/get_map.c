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

#include "../../inc/so_long.h"

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

char *read_map_content(int fd)
{
    int size;
    char *content;
    int offset = 0;

    content = (char *)malloc(sizeof(char) * 1000000);
    if (!content)
    {
        error("Error - Memory allocation failed !!\n", 1);
        return NULL;
    }
    size = read(fd, content, 1024);
    while (size > 0)
    {
        offset += size;
        size = read(fd, content + offset, 1024);
    }
    content[offset] = '\0';
    return (content);
}

char **get_map(char *file)
{
    int fd;
    char **map;
    char *content;

    fd = valid_open_file(file);
    valid_read_file(fd);
    content = read_map_content(fd);
    if (!content || ft_strlen(content) >= 4)
    {
        validate_single_character(content);
        validate_string(content);
    }
    else
        error("Error - In building the map !!\n", 1);
    close(fd);
    map = ft_split(content, '\n');
    free(content);
    return map;
}
