/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 10:30:25 by sde-carv          #+#    #+#             */
/*   Updated: 2024/08/27 08:59:29 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	len_str(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\n')
		i++;
	return (i);
}

char	*read_map_content(int fd)
{
	int		size;
	int		offset;
	char	*content;

	offset = 0;
	content = (char *)malloc(sizeof(char) * 1000000);
	if (!content)
		error("Error - Memory allocation failed !!\n");
	size = read(fd, content, 1024);
	if (size == 0)
		error_str("Error - Map empty !!\n", content);
	while (size > 0)
	{
		offset += size;
		size = read(fd, content + offset, 1024);
	}
	content[offset] = '\0';
	return (content);
}

char	**get_map(char *file)
{
	int		fd;
	char	**map;
	char	*content;

	fd = valid_open_file(file);
	content = read_map_content(fd);
	if (!content)
		error("Error - Memory allocation failed !!\n");
	if (len_str(content) >= 5)
	{
		validate_single_character(content);
		validate_string(content);
	}
	else
		error_str("Error - In building the map !!\n", content);
	close(fd);
	map = ft_split(content, '\n');
	free(content);
	return (map);
}
