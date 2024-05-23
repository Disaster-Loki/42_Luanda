/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <sde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 13:57:53 by sde-carv          #+#    #+#             */
/*   Updated: 2024/05/23 16:25:03 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*ft_strchr(const char *s, int c)
{
	size_t			i;
	unsigned char	str;

	i = 0;
	str = (unsigned char)c;
	while (s[i])
	{
		if (s[i] == str)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == str)
		return ((char *)&s[i]);
	return (NULL);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	i;

	ptr = malloc(count * size);
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (i < count * size)
		((char *)ptr)[i++] = 0;
	return (ptr);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	int		i;
	int		j;
	char	*res;
	size_t	total;

	if (!s1 || !s2)
		return (NULL);
	total = ft_strlen(s1) + ft_strlen(s2);
	res = (char *)malloc((total * sizeof(char)) + 1);
	if (res == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		res[i] = ((unsigned char *)s1)[i];
		i++;
	}
	j = 0;
	while (s2[j])
		res[i++] = ((unsigned char *)s2)[j++];
	res[i] = '\0';
	return (res);
}
