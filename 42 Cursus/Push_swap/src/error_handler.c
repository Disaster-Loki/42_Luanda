/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 11:54:10 by sde-carv          #+#    #+#             */
/*   Updated: 2024/08/02 11:25:44 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	error(char *color)
{
	ft_putstr("Error\n", color);
	exit(EXIT_FAILURE);
}

static void	val_single_argument(char *arg)
{
	int		i;
	char	**split_args;

	split_args = ft_split(arg, ' ');
	i = -1;
	while (split_args[++i])
	{
		if (!is_valid_integer(split_args[i]))
			error(DARK_ORANGE);
	}
	if (has_duplicates(split_args))
		error(DARK_ORANGE);
	free_split(split_args);
}

static void	val_multiple_arguments(int ac, char **args)
{
	int	i;

	i = 0;
	while (++i < ac)
	{
		if (!is_valid_integer(args[i]))
			error(DARK_ORANGE);
	}
	if (has_duplicates(args + 1))
		error(DARK_ORANGE);
}

int	error_handler(int ac, char **args)
{
	if (ac < 2)
		return (0);
	if (ac == 2)
		val_single_argument(args[1]);
	else
		val_multiple_arguments(ac, args);
	return (1);
}
