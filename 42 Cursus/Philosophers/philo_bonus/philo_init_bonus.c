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
		philors[i].forks = conter->forks;
		if (philors[i].pid == 0)
			process_init(&philors[i]);
	}
}

void	get_init(t_philo **philors, t_conter *conter)
{
	int	len;

	len = conter->num_ph;
	*philors = malloc(sizeof(t_philo) * conter->num_ph);
	conter->forks = sem_open("/forks", O_RDWR | O_CREAT | O_TRUNC, 0644, len);
	conter->msg = sem_open("/msg", O_CREAT, 0644, 1);
	conter->mutex_dead = sem_open("/m_dead", O_CREAT, 0644, 1);
}

void	philo_init(int av, char **args)
{
	t_conter	conter;
	t_philo		*philors;

	get_conter_init(&conter, av, args);
	get_init(&philors, &conter);
	init_philors(philors, &conter);
	wait_philos(philors, &conter);
	free(philors);
	exit(0);
}
