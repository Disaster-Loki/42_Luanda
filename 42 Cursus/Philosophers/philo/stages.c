/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stage.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 16:23:37 by sde-carv          #+#    #+#             */
/*   Updated: 2024/09/18 16:23:40 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	stage_thinking(t_philo *ph)
{
	print_msg(ph, "is thinking\n", BLUE);
}

void	stage_eating(t_philo *ph)
{
	print_msg(ph, "is eating\n", LIME);
	usleep(ph->conter->time_eat * 1000);
}

void	stage_sleeping(t_philo *ph)
{
	pthread_mutex_lock(&ph->conter->sleep);
	print_msg(ph, "is sleeping\n", D_BLUE);
	usleep(ph->conter->time_sleep * 1000);
	pthread_mutex_unlock(&ph->conter->sleep);
}

int	stage_deading(t_philo *ph)
{
	if ((current_time() - ph->time) >= ph->conter->time_die)
	{
		ph->conter->dead = 1;
		ph->conter->time_eat_ph = 0;
		print_msg(ph, "dead philosopher\n", RED);
		return (0);
	}
	return (1);
}
