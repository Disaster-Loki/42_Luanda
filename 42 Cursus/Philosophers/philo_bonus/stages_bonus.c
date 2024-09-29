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

#include "philo_bonus.h"

void	stage_thinking(t_philo *ph)
{
	print_msg(ph, "is thinking\n", BLUE);
}

void	stage_eating(t_philo *ph)
{
	sem_wait(ph->forks);
	print_msg(ph, "has taken a fork\n", YELLOW);
	sem_wait(ph->forks);
	print_msg(ph, "has taken a fork\n", YELLOW);
	print_msg(ph, "is eating\n", LIME);
	++ph->eat;
	ph->time = current_time();
	strac_usleep(ph, ph->conter->time_eat);
	sem_post(ph->forks);
	sem_post(ph->forks);
}

void	stage_sleeping(t_philo *ph)
{
	print_msg(ph, "is sleeping\n", D_BLUE);
	strac_usleep(ph, ph->conter->time_sleep);
}

int	stage_deading(t_philo *ph)
{
	long long	time_elapsed;

	time_elapsed = current_time() - ph->time;
	if (time_elapsed >= ph->conter->time_die && ph->cont == 0)
	{
		print_msg(ph, "died\n", RED);
		ph->cont = 1;
		return (0);
	}
	return (1);
}
