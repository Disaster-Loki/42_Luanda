/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 10:34:18 by sde-carv          #+#    #+#             */
/*   Updated: 2024/09/15 10:34:47 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	ft_atoi(char *str)
{
	int	sig;
	int	res;

	sig = 1;
	res = 0;
	while (*str >= 9 && *str <= 13)
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sig = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
		res = (res * 10) + (*str++ - '0');
	return (res * sig);
}

long long	current_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

int	check_args(int av, char **args)
{
	int	i;
	int	j;

	i = 0;
	while (++i < av)
	{
		j = 0;
		if (args[i][j] == '+' || args[i][j] == '-')
			j++;
		while (args[i][j])
		{
			if (args[i][j] < '0' || args[i][j] > '9')
				return (0);
			j++;
		}
	}
	return (1);
}

void	print_msg(t_philo *ph, char *str, char *color)
{
	sem_wait(ph->conter->msg);
	printf("[%lli] ", (current_time() - ph->start));
	printf("%d %s%s%s", ph->id, color, str, RESET);
	sem_post(ph->conter->msg);
}
