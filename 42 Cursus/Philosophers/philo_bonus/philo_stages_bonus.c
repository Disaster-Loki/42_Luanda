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
		strac_usleep(ph, ph->conter->time_die);
		sem_post(ph->forks);
		return (0);
	}
	return (1);
}

void	*process_init(void *date)
{
	t_philo	*ph;

	ph = (t_philo *)date;
	sem_wait(ph->conter->mutex_dead);
	while (ph->conter->time_eat_ph == 0 || ph->eat < ph->conter->time_eat_ph)
	{
		if (!stage_deading(ph))
			break ;
		if (!stage_one(ph))
			break ;
		stage_thinking(ph);
		stage_pick_up_fork(ph);
		stage_eating(ph);
		ph->eat++;
		stage_drop_fork(ph);
		stage_sleeping(ph);
	}
	sem_post(ph->conter->mutex_dead);
	return (NULL);
}

void	wait_philos(t_philo *philors, t_conter *conter)
{
	int		i;

	i = -1;
	while (++i < conter->num_ph)
		waitpid(philors[i].pid, NULL, 0);
	sem_close(conter->forks);
	sem_unlink("/forks");
	sem_close(conter->msg);
	sem_unlink("/msg");
	sem_close(conter->mutex_dead);
	sem_unlink("/m_dead");
}
