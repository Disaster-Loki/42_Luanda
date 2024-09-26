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
	sem_wait(ph->forks);
	print_msg(ph, "has taken a fork\n", YELLOW);
	sem_wait(ph->forks);
	print_msg(ph, "has taken a fork\n", YELLOW);
}

void	stage_drop_fork(t_philo *ph)
{
	sem_post(ph->forks);
	sem_post(ph->forks);
}
