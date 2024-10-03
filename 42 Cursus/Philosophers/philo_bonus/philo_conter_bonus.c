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

void	*monitor_death(void *data)
{
	t_philo		*ph;

	ph = (t_philo *)data;
	while (ph->cont == 0)
	{
		sem_wait(ph->conter->dead);
		if (!stage_deading(ph))
		{
			ph->cont = 1;
			return (NULL);
		}
		sem_post(ph->conter->dead);
		usleep(1);
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
					kill(conter->pids[i], SIGTERM);
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
