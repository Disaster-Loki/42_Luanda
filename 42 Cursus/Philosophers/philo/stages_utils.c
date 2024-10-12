/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stages_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 08:46:13 by sde-carv          #+#    #+#             */
/*   Updated: 2024/09/20 08:46:15 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	stage_pick_up_fork(t_philo *ph)
{
	if (ph->id % 2 == 0)
	{
		pthread_mutex_lock(ph->fork_left);
		print_msg(ph, "has taken a fork\n", YELLOW);
		pthread_mutex_lock(ph->fork_right);
		print_msg(ph, "has taken a fork\n", YELLOW);
	}
	else
	{
		pthread_mutex_lock(ph->fork_right);
		print_msg(ph, "has taken a fork\n", YELLOW);
		pthread_mutex_lock(ph->fork_left);
		print_msg(ph, "has taken a fork\n", YELLOW);
	}
}

void	stage_drop_fork(t_philo *ph)
{
	if (ph->id % 2 == 0)
	{
		pthread_mutex_unlock(ph->fork_left);
		pthread_mutex_unlock(ph->fork_right);
	}
	else
	{
		pthread_mutex_unlock(ph->fork_right);
		pthread_mutex_unlock(ph->fork_left);
	}
}
