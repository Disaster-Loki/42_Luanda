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
	while (1)
	{
		sem_wait(ph->conter->dead);
		if (!stage_deading(ph))
			exit(1);
		sem_post(ph->conter->dead);
		usleep(100);
	}
	return (NULL);
}

void	kill_all_philors(t_conter *conter)
{
	int		i;
	pid_t	pid;
	int		status;

	i = 0;
	while (1)
	{
		pid = waitpid(-1, &status, 0);
		if (pid == -1)
			break ;
		if (WEXITSTATUS(status))
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
	//while (waitpid(-1, &status, 0) != -1)
	//	;
}
