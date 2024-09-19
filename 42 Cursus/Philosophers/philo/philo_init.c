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

#include "philo.h"

void	get_conter_init(t_conter *conter, char **args)
{
	conter->dead = 0;
	conter->num_ph = ft_atoi(args[1]);
	conter->time_die = ft_atoi(args[2]);
	conter->time_eat = ft_atoi(args[3]);
	conter->time_sleep = ft_atoi(args[4]);
	conter->time_eat_ph = ft_atoi(args[5]);
}

void	*process_init(void *date)
{
	t_philo	*ph;

	ph = (t_philo *)date;
	while (++ph->eat < ph->conter->time_eat_ph)
	{
		stage_deading(ph);
		stage_thinking(ph);
		stage_eating(ph);
		stage_sleeping(ph);
	}
	return (NULL);
}

void	philo_init(char **args)
{
	int			i;
	t_conter	conter;
	t_philo		*philors;

	i = -1;
	get_conter_init(&conter, args);
	philors = malloc(sizeof(t_philo) * conter.num_ph);
	conter.forks = malloc(sizeof(pthread_mutex_t) * conter.num_ph);
	while (++i < conter.num_ph)
		pthread_mutex_init(&conter.forks[i], NULL);
	i = -1;
	while (++i < conter.num_ph)
	{
		philors[i].id = i + 1;
		philors[i].eat = -1;
		philors[i].conter = &conter;
		philors[i].time = current_time();
		philors[i].fork_left = &conter.forks[i];
		philors[i].fork_right = &conter.forks[(i + 1) % conter.num_ph];
		pthread_create(&philors[i].philo, NULL, process_init, &philors[i]);
	}
	i = -1;
	while (++i < conter.num_ph)
		pthread_join(philors[i].philo, NULL);
	free(conter.forks);
	free(philors);
}
