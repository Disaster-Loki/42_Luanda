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

#include "philo_bonus.h"

void	stage_pick_up_fork(t_philo *ph)
{
	if (ph->id % 2 == 0)
	{
		sem_wait(ph->fork_left);
		print_msg(ph, "has taken a fork\n", YELLOW);
		sem_wait(ph->fork_right);
		print_msg(ph, "has taken a fork\n", YELLOW);
	}
	else
	{
		usleep(2000);
		sem_wait(ph->fork_right);
		print_msg(ph, "has taken a fork\n", YELLOW);
		sem_wait(ph->fork_left);
		print_msg(ph, "has taken a fork\n", YELLOW);
	}
}

void	stage_drop_fork(t_philo *ph)
{
	if (ph->id % 2 == 0)
	{
		sem_post(ph->fork_left);
		sem_post(ph->fork_right);
	}
	else
	{
		sem_post(ph->fork_right);
		sem_post(ph->fork_left);
	}
}
