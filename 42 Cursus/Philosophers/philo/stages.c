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
	if (!stage_deading(ph))
		return ;
	print_msg(ph, "is thinking\n", BLUE);
}

void	stage_eating(t_philo *ph)
{
	if (!stage_deading(ph))
		return ;
	print_msg(ph, "is eating\n", LIME);
	strac_usleep(ph, ph->conter->time_eat);
	ph->time = current_time();
}

void	stage_sleeping(t_philo *ph)
{
	if (!stage_deading(ph))
		return ;
	print_msg(ph, "is sleeping\n", D_BLUE);
	strac_usleep(ph, ph->conter->time_sleep);
}

int	stage_deading(t_philo *ph)
{
	long long	time_elapsed;

	pthread_mutex_lock(&ph->conter->mutex_dead);
	time_elapsed = current_time() - ph->time;
	if (time_elapsed >= ph->conter->time_die && ph->conter->dead == 0)
	{
		print_msg(ph, "died\n", RED);
		ph->conter->dead = 1;
		pthread_mutex_unlock(&ph->conter->mutex_dead);
		return (0);
	}
	pthread_mutex_unlock(&ph->conter->mutex_dead);
	return (1);
}
