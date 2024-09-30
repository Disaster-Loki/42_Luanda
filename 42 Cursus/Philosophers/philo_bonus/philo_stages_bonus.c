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

#include "philo_bonus.h"

int	stage_one(t_philo *ph)
{
	if (ph->conter->num_ph == 1)
	{
		stage_thinking(ph);
		sem_wait(ph->forks);
		print_msg(ph, "has taken a fork\n", YELLOW);
		usleep(ph->conter->time_die * 1000);
		print_msg(ph, "died\n", RED);
		sem_post(ph->forks);
		return (0);
	}
	return (1);
}

void	init_philo(t_philo *ph, t_conter *conter, int n)
{
	ph->id = n;
	ph->eat = 0;
	ph->cont = 0;
	ph->conter = conter;
	ph->time = current_time();
	ph->start = current_time();
	ph->forks = conter->forks;
}

void	process_init(t_philo *ph, int n, t_conter *conter)
{
	pthread_t	monitor;

	init_philo(ph, conter, n);
	pthread_create(&monitor, NULL, monitor_death, ph);
	pthread_detach(monitor);
	while (!ph->cont && (ph->conter->time_eat_ph == 0
			|| ph->eat < ph->conter->time_eat_ph))
	{
		if (!stage_one(ph))
			break ;
		stage_thinking(ph);
		stage_eating(ph);
		++ph->eat;
		stage_sleeping(ph);
	}
	exit(0);
}