/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 16:34:22 by sde-carv          #+#    #+#             */
/*   Updated: 2024/08/26 16:34:23 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

char	*get_line(char *f_line)
{
	int		i;
	char	*line;

	i = 0;
	if (!f_line[i])
		return (NULL);
	while (f_line[i] && f_line[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (f_line[i] && f_line[i] != '\n')
	{
		line[i] = f_line[i];
		i++;
	}
	if (f_line[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*read_line(int fd, char *str)
{
	char	*tmp;
	char	*new_str;
	int		bytes;

	if (!str)
		str = ft_strdup("");
	tmp = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!tmp)
		return (NULL);
	bytes = 1;
	while (!ft_strchr(str, '\n') && bytes != 0)
	{
		bytes = read(fd, tmp, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(tmp);
			free(str);
			return (NULL);
		}
		tmp[bytes] = '\0';
		new_str = ft_strjoin(str, tmp);
		free(str);
		str = new_str;
	}
	free(tmp);
	return (str);
}

char	*get_rest(char *f_line)
{
	int		i;
	int		j;
	int		len;
	char	*rest;

	i = 0;
	while (f_line[i] && f_line[i] != '\n')
		i++;
	if (!f_line[i])
	{
		free(f_line);
		return (NULL);
	}
	len = ft_strlen(f_line) - i + 1;
	rest = (char *)malloc(sizeof(char) * len);
	if (!rest)
		return (NULL);
	i++;
	j = 0;
	while (f_line[i])
		rest[j++] = f_line[i++];
	rest[j] = '\0';
	free(f_line);
	return (rest);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;

	str = read_line(fd, str);
	if (!str)
		return (NULL);
	line = get_line(str);
	str = get_rest(str);
	return (line);
}
