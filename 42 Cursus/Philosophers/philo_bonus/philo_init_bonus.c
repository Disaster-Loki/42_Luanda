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
	*pid = malloc(sizeof(pid_t) * len);
	*philors = malloc(sizeof(t_philo) * len);
	conter->msg = sem_open("msg",  O_CREAT, 0644, 1);
	conter->dead = sem_open("dead",  O_CREAT, 0644, 1);
	conter->forks = sem_open("forks",  O_CREAT, 0644, len);
	sem_unlink("msg");
	sem_unlink("dead");
	sem_unlink("forks");
}

void free_resources(t_philo *philos, t_conter *conter)
{
    free(philos);
    free(conter->pids);
    sem_close(conter->forks);
    sem_close(conter->msg);
    sem_close(conter->dead);
    exit(0);
}

void philo_init(int av, char **args)
{
    int     i;
    t_conter conter;
    t_philo *philos;

    i = -1;
    get_conter_init(&conter, av, args);
    get_init(&philos, &conter, &conter.pids);
    while (++i < conter.num_ph)
    {
        conter.pids[i] = fork();
        if (conter.pids[i] == 0)
            process_init(&philos[i], i + 1, &conter);
    }
    kill_all_philors(conter.pids, conter.num_ph);
    free_resources(philos, &conter);
}
