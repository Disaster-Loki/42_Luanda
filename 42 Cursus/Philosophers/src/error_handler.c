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

#include "../inc/philo.h"

void	error(char *msg)
{
	ft_putstr(msg, ORANGE);
	exit(1);
}

void	error_handler(int av)
{
	if (av == 1)
		error("Error - Missing Arguments\n");
	if (av < 6)
	{
		ft_putstr("Error - [N_philo] [Time_die] [Time_eat]", ORANGE);
		error("[Time_sleep] [Time_eat_philo]\n");
	}
}
