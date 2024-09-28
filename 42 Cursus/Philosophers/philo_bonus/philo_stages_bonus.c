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
		strac_usleep(ph, ph->conter->time_die+1);
		//print_msg(ph, "died\n", RED);
		sem_post(ph->forks);
		return (0);
	}
	return (1);
}

void	process_init(t_philo *ph)
{
	pthread_t	monitor;

	pthread_create(&monitor, NULL, monitor_death, ph);
	pthread_detach(monitor);
	while (ph->conter->time_eat_ph == 0 || ph->eat < ph->conter->time_eat_ph)
	{
		if(!stage_one(ph))
			break ;
		stage_thinking(ph);
		stage_pick_up_fork(ph);
		stage_eating(ph);
		ph->eat++;
		stage_drop_fork(ph);
		stage_sleeping(ph);
	}
}

void	close_sep(t_conter *conter)
{
	sem_unlink("forks");
	sem_unlink("msg");
	sem_unlink("dead");
	sem_close(conter->forks);
	sem_close(conter->msg);
	sem_close(conter->dead);
}
