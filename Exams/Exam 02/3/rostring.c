/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rostring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 15:36:36 by sde-carv          #+#    #+#             */
/*   Updated: 2024/07/29 15:36:38 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

char	**ft_split(char *str)
{
	int	i = 0;
	int	col = 0;
	int	len = 0;
	char	**result;

	while (str[len])
		len++;
	while (*str == ' ' || *str == '\t')
		str++;
	result = (char **)malloc(sizeof(char *) * (len + 1));
	if (!result)
		return (NULL);
	while (*str)
	{
		col = 0;
		result[i] = (char *)malloc(sizeof(char) * (len + 1));
		while (*str && *str != ' ' && *str != '\t')
			result[i][col++] = *str++;
		while (*str == ' ' || *str == '\t')
			str++;
		result[i++][col] = '\0';
	}
	result[i] = NULL;
	return (result);
}

int	main(int av, char **args)
{
	if (av != 1)
	{
		int	i = 1;
		int	j = 0;
		char	*str = args[1];
		char	**res = ft_split(str);
		while (res[i])
		{
			j = 0;
			if(i > 1)
				ft_putchar(' ');
			while (res[i][j])
				ft_putchar(res[i][j++]);
			i++;
		}
		if (res[1])
			ft_putchar(' ');
		j = 0;
		while (res[0][j])
				ft_putchar(res[0][j++]);
	}
	ft_putchar('\n');
	return (0);
}
