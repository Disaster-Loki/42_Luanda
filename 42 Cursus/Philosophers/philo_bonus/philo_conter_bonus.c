/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_conter_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 12:41:40 by sde-carv          #+#    #+#             */
/*   Updated: 2024/10/04 11:21:36 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*monitor_death(void *data)
{
	t_philo		*ph;

	ph = (t_philo *)data;
	while (!ph->stop)
	{
		sem_wait(ph->conter->dead);
		if (!stage_deading(ph))
		{
			ph->stop = 1;
			break;
		}
		sem_post(ph->conter->dead);
		if (ph->conter->meal_eat_ph > 0
			&& ph->eat == ph->conter->meal_eat_ph)
			break ;
	}
	return (NULL);
}

void	kill_all_philors(t_conter *conter)
{
	int		i;
	pid_t	pid;
	int		status;

	i = 0;
	status = 0;
	while (status != 256)
	{
		pid = waitpid(-1, &status, 0);
		if (pid == -1)
			break ;
		if (status == 256)
		{
			while (i < conter->num_ph)
			{
				if (conter->pids[i])
					kill(conter->pids[i], SIGKILL);
				i++;
			}
			break ;
		}
	}
}

void	free_resources(t_conter *conter)
{
	if (conter->pids)
		free(conter->pids);
	sem_close(conter->msg);
	sem_close(conter->dead);
	sem_close(conter->order);
	sem_close(conter->forks);
}
