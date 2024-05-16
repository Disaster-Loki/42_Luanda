/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 09:52:15 by sde-carv          #+#    #+#             */
/*   Updated: 2023/12/05 09:52:38 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		print(str[i]);
		i++;
	}
}

int	ft_strcmp(char *str, char *str2)
{
	int	i;

	i = 0;
	while (str[i] == str2[i] && (str[i] != '\0' && str2[i] != '\0'))
		i++;
	return (str[i] - str2[i]);
}

char	**ft_sort_params(int argc, char **argv)
{
	int		i;
	char	*but;

	i = 1;
	while (i < argc)
	{
		while (i < argc - 1)
		{
			if (ft_strcmp(argv[i], argv[i + 1]) > 0)
			{
				but = argv[i + 1];
				argv[i + 1] = argv[i];
				argv[i] = but;
			}
			i++;
		}
		i = 1;
		argc--;
	}
	return (argv);
}

int	main(int av, char **args)
{
	int		i;
	char	**mod;

	i = 1;
	mod = ft_sort_params(av, args);
	while (i < av)
	{
		ft_putstr(args[i]);
		if (i < av - 1)
			print('\n');
		i++;
	}
	return (0);
}
