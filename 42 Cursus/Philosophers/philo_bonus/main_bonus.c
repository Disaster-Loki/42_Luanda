/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 10:15:27 by sde-carv          #+#    #+#             */
/*   Updated: 2024/09/15 10:16:50 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	get_conter_init(t_conter *conter, int av, char **args)
{
	conter->time_eat_ph = 0;
	conter->num_ph = ft_atoi(args[1]);
	conter->time_die = ft_atoi(args[2]);
	conter->time_eat = ft_atoi(args[3]);
	conter->time_sleep = ft_atoi(args[4]);
	if (av == 6)
		conter->time_eat_ph = ft_atoi(args[5]);
}

void	get_init(t_philo **philors, t_conter *conter, pid_t **pid)
{
	int	len;

	len = conter->num_ph;
	*philors = malloc(sizeof(t_philo) * len);
	*pid = malloc(sizeof(pid_t) * len);
	conter->forks = sem_open("forks",  O_CREAT | O_EXCL, 0644, len);
	conter->msg = sem_open("msg",  O_CREAT | O_EXCL, 0644, 1);
	conter->dead = sem_open("dead",  O_CREAT | O_EXCL, 0644, 0);
}

void	philo_init(int av, char **args)
{
	int		i;
	pid_t		*pid;
	t_conter	conter;
	t_philo		*philos;

	i = -1;
	get_conter_init(&conter, av, args);
	get_init(&philos, &conter, &pid);
	init_philors(philos, &conter);
	while (++i < conter.num_ph)
	{
		pid[i] = fork();
		if (pid[i] == 0)
			process_init(&philos[i]);
	}
	kill_all_philors(pid, conter.num_ph);
	close_sep(&conter);
	free(pid);
	free(philos);
	exit(0);
}

int	main(int av, char **args)
{
	if (!error_handler(av, args))
		return (0);
	philo_init(av, args);
	return (0);
}
