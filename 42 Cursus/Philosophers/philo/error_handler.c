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
		error("Error - check the parameters\n");
		return (0);
	}
	if (ft_atoi(args[1]) > 200)
	{
		error("Error - many philosophers\n");
		return (0);
	}
	if (ft_atoi(args[2]) < 60 || ft_atoi(args[3]) < 60 || ft_atoi(args[2]) < 60)
	{
		error("Error - Timers minimum parameter 60 ms\n");
		return (0);
	}
	return (1);
}
