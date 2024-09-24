/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_stage.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 10:39:57 by sde-carv          #+#    #+#             */
/*   Updated: 2024/09/20 10:40:02 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	stage_one(t_philo *ph)
{
	if (ph->conter->num_ph == 1)
	{
		stage_thinking(ph);
		pthread_mutex_lock(ph->fork_left);
		print_msg(ph, "has taken a fork\n", YELLOW);
		strac_usleep(ph, ph->conter->time_die);
		print_msg(ph, "died\n", RED);
		ph->conter->dead = 1;
		pthread_mutex_unlock(ph->fork_left);
		return (1);
	}
	return (0);
}

void	*process_init(void *date)
{
	t_philo	*ph;

	ph = (t_philo *)date;
	while (ph->conter->time_eat_ph == 0 || ph->eat < ph->conter->time_eat_ph)
	{
		if (!stage_deading(ph))
			break ;
		if (stage_one(ph))
			break ;
		stage_thinking(ph);
		stage_pick_up_fork(ph);
		stage_eating(ph);
		ph->eat++;
		stage_drop_fork(ph);
		stage_sleeping(ph);
		pthread_mutex_lock(&ph->conter->mutex_dead);
		if (ph->conter->dead)
		{
			pthread_mutex_unlock(&ph->conter->mutex_dead);
			break ;
		}
		pthread_mutex_unlock(&ph->conter->mutex_dead);
	}
	return (NULL);
}

void	wait_philos(t_philo *philors, t_conter *conter)
{
	int	i;

	i = -1;
	while (++i < conter->num_ph)
		pthread_join(philors[i].philo, NULL);
}
