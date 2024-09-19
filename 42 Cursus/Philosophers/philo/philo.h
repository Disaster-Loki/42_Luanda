/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 17:12:49 by sde-carv          #+#    #+#             */
/*   Updated: 2024/09/13 17:13:54 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

# define RESET "\033[0m"
# define BLUE "\033[38;2;0;0;255m"
# define LIME "\033[38;2;0;255;0m"
# define RED "\033[38;2;255;0;0m"
# define YELLOW "\033[38;2;255;255;0m"
# define ORANGE "\033[38;2;255;140;0m"
# define D_BLUE "\033[38;2;30;144;255m" 

typedef struct s_conter
{
	int				num_ph;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				time_eat_ph;
	int				dead;
	pthread_mutex_t	*forks;
	pthread_mutex_t	sleep;
}	t_conter;

typedef struct s_philo
{
	int				id;
	int				eat;
	pthread_t		philo;
	long long		time;
	t_conter		*conter;
	long long		last_eat;
	pthread_mutex_t	*fork_left;
	pthread_mutex_t	*fork_right;
}	t_philo;

void	error(char *msg);
long long	current_time();
int		ft_atoi(char *str);
void	error_handler(int av);
void	*process_init(void *date);
void	get_conter_init(t_conter *conter, char **args);
void	philo_init(char **args);
void	stage_eating(t_philo *ph);
int		stage_deading(t_philo *ph);
void	stage_thinking(t_philo *ph);
void	stage_sleeping(t_philo *ph);
void	print_msg(t_philo *ph, char *str, char *color);

#endif