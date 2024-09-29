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
	long long	time_elapsed;
	
	ph = (t_philo *)data;
	while (!ph->cont)
	{
		time_elapsed = current_time() - ph->time;
		if (time_elapsed >= ph->conter->time_die)
		{
			sem_wait(ph->conter->dead);
			print_msg(ph, "died\n", RED);
			sem_post(ph->conter->dead);
			kill_all_philors(ph->conter->pids, ph->conter->num_ph);
			exit(1);
		}
		usleep(20);
	}
	return (NULL);
}

void	kill_all_philors(pid_t *pids, int num)
{
	int		i;
	pid_t	pid;
	int		status;
	
	i = -1;
	while (1)
	{
		pid = waitpid(-1, &status, 0);
		if (pid == -1)
			break ;
		if (WEXITSTATUS(status))
		{
			while (++i < num)
			{
				if (pids[i])
				{
					kill(pids[i], SIGTERM);
				}
			}
			break ;
		}
	}
	while (waitpid(-1, &status, 0) != -1)
		;
}
