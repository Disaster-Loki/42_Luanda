/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 11:11:03 by sde-carv          #+#    #+#             */
/*   Updated: 2024/09/29 11:11:06 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	get_conter_init(t_conter *conter, int av, char **args)
{
	conter->meal_eat_ph = 0;
	conter->num_ph = ft_atoi(args[1]);
	conter->time_die = ft_atoi(args[2]);
	conter->time_eat = ft_atoi(args[3]);
	conter->time_sleep = ft_atoi(args[4]);
	if (av == 6)
		conter->meal_eat_ph = ft_atoi(args[5]);
}

void	get_init(t_conter *conter)
{
	int	len;

	len = conter->num_ph;
	conter->pids = malloc(sizeof(pid_t) * len);
	conter->msg = sem_open("msg", O_CREAT, 0644, 1);
	conter->dead = sem_open("dead", O_CREAT, 0644, 1);
	conter->forks = sem_open("forks", O_CREAT, 0644, len);
	if (conter->msg == SEM_FAILED || conter->dead == SEM_FAILED
		|| conter->forks == SEM_FAILED)
		error("Error - Failed to open semaphore\n");
	sem_unlink("msg");
	sem_unlink("dead");
	sem_unlink("forks");
}

void	philo_init(int av, char **args)
{
	int			i;
	t_conter	conter;

	i = -1;
	get_conter_init(&conter, av, args);
	get_init(&conter);
	while (++i < conter.num_ph)
	{
		conter.pids[i] = fork();
		if (conter.pids[i] == 0)
			process_init(&conter, i + 1);
	}
	kill_all_philors(&conter);
	free_resources(&conter);
}
