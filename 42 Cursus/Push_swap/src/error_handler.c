/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 11:54:10 by sde-carv          #+#    #+#             */
/*   Updated: 2024/08/01 11:54:12 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static int	ft_isdigit_string(char *s)
{
	while (*s)
	{
		if (!ft_isdigit(*s) && *s != ' ')
			return (0);
		s++;
	}
	return (1);
}

static int	is_valid_integer(char *s)
{
	long	num;
	int		sign;

	sign = 1;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	if (!*s)
		return (0);
	num = 0;
	while (*s)
	{
		if (!ft_isdigit(*s))
			return (0);
		num = num * 10 + (*s - '0');
		if (num * sign > INT_MAX || num * sign < INT_MIN)
			return (0);
		s++;
	}
	return (1);
}

static int	has_duplicates(char **args)
{
	int i;
	int j;

	i = 0;
	while (args[i])
	{
		j = i + 1;
		while (args[j])
		{
			if (ft_atoi(args[i]) == ft_atoi(args[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static void	check_arguments_format(int av, char **args)
{
	int		i;
	char	**split_args;

	if (av == 2)
	{
		if (!ft_isdigit_string(args[1]) || !is_valid_integer(args[1]))
		{
			ft_putstr("Error\n", RED);
			exit(EXIT_FAILURE);
		}
	}
	else if (av > 2)
	{
		split_args = ft_split(args[1], ' ');
		if (!split_args)
		{
			ft_putstr("Error - Memory Allocation Failure\n", RED);
			exit(EXIT_FAILURE);
		}
		i = 0;
		while (split_args[i])
		{
			if (!is_valid_integer(split_args[i]))
			{
				ft_putstr("Error\n", RED);
				free_split(split_args);
				exit(EXIT_FAILURE);
			}
			i++;
		}
		if (has_duplicates(split_args))
		{
			ft_putstr("Error - Duplicate Numbers\n", DARK_ORANGE);
			free_split(split_args);
			exit(EXIT_FAILURE);
		}
		i = 0;
		while (split_args[i])
			free(split_args[i++]);
		free(split_args);
	}
}

void	error_handler(int av, char **args)
{
	if (av < 2)
	{
		ft_putstr("Error - Incomplete Parameters\n", DARK_ORANGE);
		exit(EXIT_FAILURE);
	}
	check_arguments_format(av, args);
}

