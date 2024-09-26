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
	if (!stage_deading(ph))
		return ;
	print_msg(ph, "is thinking\n", BLUE);
}

void	stage_eating(t_philo *ph)
{
	if (!stage_deading(ph))
		return ;
	print_msg(ph, "is eating\n", LIME);
	strac_usleep(ph, ph->conter->time_eat);
}

void	stage_sleeping(t_philo *ph)
{
	if (!stage_deading(ph))
		return ;
	print_msg(ph, "is sleeping\n", D_BLUE);
	strac_usleep(ph, ph->conter->time_sleep);
}

int	stage_deading(t_philo *ph)
{
	long long	time_elapsed;

	time_elapsed = current_time() - ph->time;
	if (time_elapsed >= ph->conter->time_die)
	{
		print_msg(ph, "died\n", RED);
		//sem_post(ph->conter->mutex_dead);
		return (0);
	}
	return (1);
}
