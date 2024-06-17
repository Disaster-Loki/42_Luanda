/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <sde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 11:35:12 by sde-carv          #+#    #+#             */
/*   Updated: 2024/06/17 09:36:13 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_validate_pid(char *pid_str)
{
	int		i;
	pid_t	server_pid;

	i = -1;
	server_pid = ft_atoi(pid_str);
	while (pid_str[++i])
	{
		if (!ft_isdigit(pid_str[i]))
		{
			ft_putstr("Error - Invalid PID\n");
			exit(EXIT_FAILURE);
		}
	}
	if (kill(server_pid, 0) == -1)
	{
		ft_putstr("Error - Server PID not accessible\n");
		exit(EXIT_FAILURE);
	}
}

void	ft_check(int ac, char **av)
{
	if (ac != 3)
	{
		ft_putstr("Error - Usage: ./client [server_pid] [message]\n");
		exit(EXIT_FAILURE);
	}
	ft_validate_pid(av[1]);
	if (!av[2][0])
	{
		ft_putstr("Error - Invalid message\n");
		exit(EXIT_FAILURE);
	}
}
