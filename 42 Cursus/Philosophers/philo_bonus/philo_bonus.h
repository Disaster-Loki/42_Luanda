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

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <wait.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <semaphore.h>

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
	int				meal_eat_ph;
	pid_t			*pids;
	sem_t			*msg;
	sem_t			*dead;
	sem_t			*forks;
	sem_t			*order;
}	t_conter;

typedef struct s_philo
{
	int				id;
	int				eat;
	int				stop;
	long long		time;
	long long		start;
	sem_t			*forks;
	t_conter		*conter;
	pthread_t		monitor;
}	t_philo;

void		error(char *msg);
long long	current_time(void);
int			ft_atoi(char *str);
int			stage_one(t_philo *ph);
void		stage_eating(t_philo *ph);
void		get_init(t_conter *conter);
void		*monitor_death(void *date);
int			stage_deading(t_philo *ph);
void		stage_thinking(t_philo *ph);
void		stage_sleeping(t_philo *ph);
void		stage_drop_fork(t_philo *ph);
void		philo_init(int av, char **args);
int			check_args(int av, char **args);
void		stage_pick_up_fork(t_philo *ph);
void		free_resources(t_conter *conter);
int			error_handler(int av, char **args);
void		kill_all_philors(t_conter *conter);
void		process_init(t_conter *conter, int n);
void		print_msg(t_philo *ph, char *str, char *color);
void		init_philo(t_philo *ph, t_conter *conter, int n);
void		get_conter_init(t_conter *conter, int av, char **args);

#endif
