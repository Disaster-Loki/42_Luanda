/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <sde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 13:57:34 by sde-carv          #+#    #+#             */
/*   Updated: 2024/05/23 16:26:29 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_buff(int fd, char *buff, int *end_bool)
{
	size_t	r_size;

	if (buff)
		return (buff);
	buff = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buff)
		return (NULL);
	r_size = read(fd, buff, BUFFER_SIZE);
	if (r_size <= 0)
	{
		free(buff);
		return (NULL);
	}
	buff[r_size] = '\0';
	if (r_size < BUFFER_SIZE && !ft_strchr(buff, '\n'))
		*end_bool = 1;
	return (buff);
}

char	*read_and_join(int fd, char *buff, int *end_bool)
{
	char	*buff2;
	char	*new_buff;
	size_t	r_size;

	buff2 = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buff2)
		return (NULL);
	r_size = read(fd, buff2, BUFFER_SIZE);
	if (r_size <= 0)
	{
		free(buff2);
		return (buff);
	}
	buff2[r_size] = '\0';
	new_buff = ft_strjoin(buff, buff2);
	free(buff);
	free(buff2);
	if (!new_buff)
		return (NULL);
	if (r_size < BUFFER_SIZE && !ft_strchr(new_buff, '\n'))
		*end_bool = 1;
	return (new_buff);
}

char	*get_new_buff(char *buff, char **ret_str)
{
	char	*new_buff;

	new_buff = ft_strjoin("", ft_strchr(buff, 10) + 1);
	if (!new_buff)
		return (NULL);
	ft_strchr(buff, 10)[1] = '\0';
	*ret_str = ft_strjoin("", buff);
	free(buff);
	return (new_buff);
}

char	*get_next_line(int fd)
{
	static char	*buff;
	char		*ret_str;
	int			end_bool;

	end_bool = 0;
	if (BUFFER_SIZE <= 0 || fd < 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buff = read_buff(fd, buff, &end_bool);
	while (buff && !end_bool && !ft_strchr(buff, '\n'))
		buff = read_and_join(fd, buff, &end_bool);
	if (!buff)
		return (NULL);
	buff = get_new_buff(buff, &ret_str);
	if (!ret_str)
		return (NULL);
	if (end_bool && !buff)
		buff = NULL;
	return (ret_str);
}
