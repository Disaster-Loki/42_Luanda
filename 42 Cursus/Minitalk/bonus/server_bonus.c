/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <sde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 11:30:12 by sde-carv          #+#    #+#             */
/*   Updated: 2024/06/15 13:11:53 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"
#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

static int	g_r_bit;

void	rest(int signal, siginfo_t *siginfo, void *context)
{
	static unsigned char	buff;

	(void)context;
	if (signal == SIGUSR1)
		buff |= 1;
	g_r_bit++;
	if (g_r_bit == 8)
	{
		write(1, &buff, 1);
		g_r_bit = 0;
		buff = 0;
		if (kill(siginfo->si_pid, SIGUSR1) == -1)
		{
			ft_printf("Error sending ACK signal");
			exit(EXIT_FAILURE);
		}
	}
	else
		buff = buff << 1;
}

void	sig_handler(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = &rest;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		perror("Error - Problem receiving SIGUSR1");
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		perror("Error - Problem receiving SIGUSR2");
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	printf("Server PID: %i\n", pid);
	sig_handler();
	while (1)
		pause();
	return (0);
}
