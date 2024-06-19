/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <sde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 09:35:19 by sde-carv          #+#    #+#             */
/*   Updated: 2024/06/17 10:23:18 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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
		ft_putstr("Error - Problem receiving SIGUSR1");
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		ft_putstr("Error - Problem receiving SIGUSR2");
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	ft_putstr("Server PID: ");
	ft_putnbr(pid);
	ft_putchar('\n');
	sig_handler();
	while (1)
		pause();
	return (0);
}
