/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_stage.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 10:39:57 by sde-carv          #+#    #+#             */
/*   Updated: 2024/09/20 10:40:02 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	wait_philos(t_philo *philors, t_conter *conter)
{
	int	i;

	i = -1;
	while (++i < conter->num_ph)
		pthread_join(philors[i].philo, NULL);
}

void	*process_init(void *date)
{
	t_philo	*ph;

	ph = (t_philo *)date;
	while (1)
	{
		if (ph->conter->dead)
			break ;
		if (!stage_deading(ph))
			break ;
		stage_thinking(ph);
		stage_pick_up_fork(ph);
		stage_eating(ph);
		stage_drop_fork(ph);
		stage_sleeping(ph);
	}
	return (NULL);
}
