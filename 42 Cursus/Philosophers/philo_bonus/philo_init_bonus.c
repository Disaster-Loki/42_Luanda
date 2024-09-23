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

void	get_conter_init(t_conter *conter, int av, char **args)
{
	conter->dead = 0;
	conter->time_eat_ph = 0;
	conter->num_ph = ft_atoi(args[1]);
	conter->time_die = ft_atoi(args[2]);
	conter->time_eat = ft_atoi(args[3]);
	conter->time_sleep = ft_atoi(args[4]);
	if (av == 6)
		conter->time_eat_ph = ft_atoi(args[5]);
}

void	init_philors(t_philo *philors, t_conter *conter)
{
	int	i;

	i = -1;
	while (++i < conter->num_ph)
	{
		philors[i].eat = 0;
		philors[i].id = i + 1;
		philors[i].pid = fork();
		philors[i].conter = conter;
		philors[i].time = current_time();
		philors[i].start = current_time();
		philors[i].fork_left = conter->forks[i];
		philors[i].fork_right = conter->forks[(i + 1) % conter->num_ph];
		process_init(&philors[i]);
	}
}

void	get_init(t_philo **philors, t_conter *conter)
{
	int	i;

	i = -1;
	*philors = malloc(sizeof(t_philo) * conter->num_ph);
	conter->forks = malloc(sizeof(sem_t *) * conter->num_ph);
	if (!conter->forks)
		return ;
	while (++i < conter->num_ph)
	{
		conter->forks[i] = sem_open("/process_philo", O_CREAT, 0644, 1);
		if (conter->forks[i] == SEM_FAILED)
			error("Error - Failed to create Semaphore");
	}
	ft_memset(&conter->msg, 0, sizeof(sem_t));
	ft_memset(&conter->mutex_dead, 0, sizeof(sem_t));
}

void	philo_init(int av, char **args)
{
	t_conter	conter;
	t_philo		*philors;

	get_conter_init(&conter, av, args);
	get_init(&philors, &conter);
	init_philors(philors, &conter);
	wait_philos(philors, &conter);
	free(conter.forks);
	free(philors);
}
