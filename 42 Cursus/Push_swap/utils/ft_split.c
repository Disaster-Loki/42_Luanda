/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 16:14:59 by sde-carv          #+#    #+#             */
/*   Updated: 2024/07/31 16:15:02 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	ft_strlcpy(char *dst, char *src, int size)
{
	int	i;

	i = -1;
	while (src[++i] && i + 1 < size)
		dst[i] = src[i];
	if (i < size)
		dst[i] = '\0';
	while (src[i])
		i++;
	return (i);
}

int	ft_toklen(char *str, char c)
{
	int	len;

	len = 0;
	while (*str)
	{
		if (*str != c)
		{
			++len;
			while (*str && *str != c)
				++str;
		}
		else
			++str;
	}
	return (len);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*str;
	char	*src;

	src = (char *)s;
	if (!src)
		return (NULL);
	if ((int)start >= ft_strlen(s))
	{
		str = (char *)malloc(sizeof(char));
		if (!str)
			return (NULL);
		*str = '\0';
	}
	else
	{
		if ((ft_strlen(s) - start) < len)
			len = ft_strlen(s) - start;
		str = (char *)malloc((sizeof(char) * len) + 1);
		if (!str)
			return (NULL);
		ft_strlcpy(str, (char *)(s + start), len + 1);
	}
	return (str);
}

char	**ft_split(char *s, char c)
{
	int		i;
	int		len;
	char	**new;

	if (!s)
		return (0);
	i = 0;
	new = (char **)malloc(sizeof(char *) * (ft_toklen(s, c) + 1));
	if (!new)
		return (NULL);
	while (*s)
	{
		if (*s != c)
		{
			len = 0;
			while (*s && *s != c && ++len)
				++s;
			new[i++] = ft_substr((s - len), 0, len);
		}
		else
			++s;
	}
	new[i] = '\0';
	return (new);
}
