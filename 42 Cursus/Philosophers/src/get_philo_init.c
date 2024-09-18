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

#include "../inc/philo.h"

void	get_conter_init(t_philo *philo, char **args)
{
	philo->conter.num_ph = ft_atoi(args[1]);
	philo->conter.time_die = ft_atoi(args[2]);
	philo->conter.time_eat = ft_atoi(args[3]);
	philo->conter.time_sleep = ft_atoi(args[4]);
	philo->conter.time_eat_ph = ft_atoi(args[5]);
}

void	*process_init(void *date)
{
	int	ph;

	ph = *(int *) date;
	sleep(1);
	printf("Test: %d\n", ph);
	return (NULL);
}

void	philo_init(char **args)
{
	int		i;
	t_philo	philo;

	i = -1;
	get_conter_init(&philo, args);
	philo.philors = malloc(sizeof(pthread_t) * philo.conter.num_ph);
	philo.forks = malloc(sizeof(pthread_mutex_t) * philo.conter.num_ph);
	while (++i < philo.conter.num_ph)
	{
		philo.id = i + 1;
		printf("Philo: %d\n", philo.id);
		pthread_mutex_init(&philo.forks[i], NULL);
		pthread_create(&philo.philors[i], NULL, &process_init, &philo.id);
	}
	i = -1;
	while (++i < philo.conter.num_ph)
		pthread_join(philo.philors[i], NULL);
	i = -1;
	while (++i < philo.conter.num_ph)
		pthread_mutex_destroy(&philo.forks[i]);
	free(philo.forks);
	free(philo.philors);
}
