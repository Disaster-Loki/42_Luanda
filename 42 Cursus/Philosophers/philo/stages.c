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

#include "philo.h"

void	stage_thinking(t_philo *ph)
{
	print_msg(ph, "is thinking\n", BLUE);
}

void	stage_eating(t_philo *ph)
{
	ph->time = current_time();
	usleep(ph->conter->time_eat * 1000);
	print_msg(ph, "is eating\n", LIME);
	pthread_mutex_lock(&ph->conter->msg);
	if (!stage_deading(ph))
	{
		pthread_mutex_unlock(&ph->conter->msg);
		return ;
	}
	pthread_mutex_unlock(&ph->conter->msg);
}

void	stage_sleeping(t_philo *ph)
{
	ph->time = current_time();
	usleep(ph->conter->time_sleep * 1000);
	print_msg(ph, "is sleeping\n", D_BLUE);
	pthread_mutex_lock(&ph->conter->msg);
	if (!stage_deading(ph))
	{
		pthread_mutex_unlock(&ph->conter->msg);
		return ;
	}
	pthread_mutex_unlock(&ph->conter->msg);
}

int	stage_deading(t_philo *ph)
{
	if ((current_time() - ph->time) >= ph->conter->time_die)
	{
		if (ph->conter->dead == 0)
		{
			pthread_mutex_unlock(&ph->conter->msg);
			ph->conter->dead = 1;
			print_msg(ph, "dead philosopher\n", RED);
			pthread_mutex_unlock(&ph->conter->msg);
		}
		return (0);
	}
	return (1);
}
