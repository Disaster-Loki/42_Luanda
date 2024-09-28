/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_philo_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 12:41:40 by sde-carv          #+#    #+#             */
/*   Updated: 2024/09/15 12:42:01 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	kill_all_philors(pid_t *pids, int num)
{
	int	i;
	int	st;
	pid_t	pid;
	
	i = -1;
	while (1)
	{
		pid = waitpid(-1, &st, 0);
		if (pid == -1)
			break ;
		if (WEXITSTATUS(st))
		{
			while (++i < num)
				kill(pids[i], SIGTERM);
			break ;
		}
	}
	while (waitpid(-1, &st, 0) != -1)
	{
	}
}

void	*monitor_death(void *date)
{
	t_philo	*ph;
	
	ph = (t_philo *) date;
	while (!ph->stop)
	{
		if (!stage_deading(ph))
		{
			sem_post(ph->conter->dead);
			exit(1);
			return (NULL);
		}
		usleep(200);
	}
	return (NULL);
}

void	init_philors(t_philo *philors, t_conter *conter)
{
	int	i;

	i = -1;
	while (++i < conter->num_ph)
	{
		philors[i].eat = 0;
		philors[i].id = i + 1;
		philors[i].stop = 0;
		philors[i].conter = conter;
		philors[i].time = current_time();
		philors[i].start = current_time();
		philors[i].forks = conter->forks;
	}
}

