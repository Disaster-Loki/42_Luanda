/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <sde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 13:57:34 by sde-carv          #+#    #+#             */
/*   Updated: 2024/05/24 17:19:19 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*full_string;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	full_string = ft_read(fd, full_string);
	if (!full_string)
		return (NULL);
	line = ft_getline(full_string);
	full_string = ft_getrest(full_string);
	return (line);
}

char	*ft_read(int fd, char *str)
{
	char	*tmp;
	int		bytes;

	tmp = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!tmp)
		return (NULL);
	bytes = 1;
	while (!ft_strchr(str, '\n') && (bytes != 0))
	{
		bytes = read(fd, tmp, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(tmp);
			return (NULL);
		}
		tmp[bytes] = '\0';
		str = ft_strjoin(str, tmp);
	}
	free(tmp);
	return (str);
}

char	*ft_getline(char *full_string)
{
	int		i;
	char	*line;

	i = 0;
	if (!full_string[i])
		return (NULL);
	while (full_string[i] && full_string[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (full_string[i] && full_string[i] != '\n')
	{
		line[i] = full_string[i];
		i++;
	}
	if (full_string[i] == '\n')
	{
		line[i] = full_string[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_getrest(char *full_string)
{
	int		i;
	int		j;
	char	*restof;

	i = 0;
	while (full_string[i] && full_string[i] != '\n')
		i++;
	if (!full_string[i])
	{
		free(full_string);
		return (NULL);
	}
	restof = (char *)malloc(sizeof(char) * (ft_strlen(full_string) - i + 1));
	if (!restof)
		return (NULL);
	i++;
	j = 0;
	while (full_string[i])
		restof[j++] = full_string[i++];
	restof[j] = '\0';
	free(full_string);
	return (restof);
}
