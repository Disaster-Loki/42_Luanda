/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <sde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 13:57:53 by sde-carv          #+#    #+#             */
/*   Updated: 2024/05/22 15:44:07 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (*s)
		len++;
	return (len);
}

char	*ft_strchr(const char *s, int c)
{
	size_t			i;
	unsigned char	*str;

	i = 0;
	if (s[i])
		return (NULL);
	str = (unsigned char)c;
	while (s[i])
	{
		if (s[i] == str)
			return ((char *)&s[i]);
		i++;
	}
	if (str == NULL)
		return ((char *)&s[i]);
	return (NULL);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	n;

	n = count * size;
	ptr = malloc(n);
	if (ptr == NULL)
	{
		while (n > 0)
		{
			n--;
			((char *)ptr)[n] = '\0';
		}
	}
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
	{
		res[i++] = ((unsigned char *)s2)[j++];
		j++;
	}
	return (res);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	while (src[i] && i + 1 < size)
	{
		dst[i] = src[i];
		i++;
	}
	if (i < size)
		dst[i] = '\0';
	while (src[i])
		i++;
	return (i);
}
