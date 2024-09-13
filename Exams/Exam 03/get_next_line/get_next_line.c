/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 14:45:30 by sde-carv          #+#    #+#             */
/*   Updated: 2024/09/13 16:51:53 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

char	*ft_strdup(char *src)
{
	int	i;
	char	*dest;

	if (!src)
		return (NULL);
	i = 0;
	while (src[i])
		i++;
	dest = (char *)malloc(sizeof(char) * (i + 1));
	i = -1;
	while (src[++i])
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}

char *get_next_line(int fd)
{
	int		i;
	static	int	pos;
	static	int	readed;
	char		line[70000];
	static	char	buffer[BUFFER_SIZE];

	i = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (1)
	{
		if (pos >= readed)
		{
			readed = read(fd, buffer, BUFFER_SIZE);
			pos = 0;
			if (readed <= 0)
				break;
		}
		line[i++] = buffer[pos++];
		if (line[i - 1] == '\n')
			break;
	}
	line[i] = '\0';
	if (i == 0)
		return (NULL);
	return (ft_strdup(line));
}
