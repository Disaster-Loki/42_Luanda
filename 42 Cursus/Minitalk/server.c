/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <sde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 17:04:08 by sde-carv          #+#    #+#             */
/*   Updated: 2024/06/14 11:49:24 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	rest(int signal, siginfo *siginfo)
{
	static unsigned char	buff;
	static int				r_bit;

	r_bit = 0
	if (signal == SIGUSR1)
		buff |= 1;
	r_bit++;
	if (r_bit == 8)
	{
		write(1, &buff, 1);
		r_bit = 0;
		buff = 0;
	}
	else
		buff = buff << 1;
	kill(siginfo->si_pid, SIGUSR1);
}

void	sig_handler(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = &rest;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		(ft_printf("Error - Problem receiving signal"));
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		(ft_printf("Error - Problem receiving signal"));
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	ft_printf("Server PID: %i\n", pid);
	sig_handler();
	while (1)
		pause();
	return (0);
}
