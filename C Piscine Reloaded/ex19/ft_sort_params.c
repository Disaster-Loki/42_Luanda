/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 11:59:57 by sde-carv          #+#    #+#             */
/*   Updated: 2024/05/07 12:43:37 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

int	ft_strcmp(char *s1, char *s2)
{
	int	index;

	index = 0;
	while ((s1[index] == s2[index]) && (s1[index] && s2[index] != '\0'))
		index++;
	return (s1[index] - s2[index]);
}

void	ft_print_params(char *argv[])
{
	int	index;
	int	column;

	index = 1;
	while (argv[index])
	{
		column = 0;
		while (argv[index][column])
		{
			ft_putchar(argv[index][column]);
			column++;
		}
		ft_putchar('\n');
		index++;
	}
}

int	main(int argc, char *argv[])
{
	int		index;
	int		column;
	char	*temporary;

	index = 1;
	while (index < argc)
	{
		column = 1;
		while (column < argc)
		{
			if (ft_strcmp(argv[index], argv[column]) < 0)
			{
				temporary = argv[index];
				argv[index] = argv[column];
				argv[column] = temporary;
			}
			column++;
		}
		index++;
	}
	ft_print_params(argv);
	return (0);
}
