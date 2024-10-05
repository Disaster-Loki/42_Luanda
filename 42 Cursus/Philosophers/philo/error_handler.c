/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 10:44:35 by sde-carv          #+#    #+#             */
/*   Updated: 2024/09/15 10:44:52 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	error(char *msg)
{
	printf("%s%s%s", msg, ORANGE, RESET);
}

int	error_handler(int av, char **args)
{
	if (av != 5 && av != 6)
	{
		error("Error - Check the parameters\n");
		return (0);
	}
	if (ft_atoi(args[1]) < 1 || ft_atoi(args[1]) > 200)
	{
		error("Error - Invalid number of philosophers\n");
		return (0);
	}
	if (!check_args(av, args))
	{
		error("Error - Invalid parameters\n");
		return (0);
	}
	return (1);
}
