/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <sde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 09:35:38 by sde-carv          #+#    #+#             */
/*   Updated: 2024/06/17 11:27:40 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static int	g_send_bit;

void	send_signal(int signal)
{
	if (signal == SIGUSR1 || signal == SIGUSR2)
		g_send_bit = 1;
}

void	sig_handler(void)
{
	struct sigaction	sa;

	sa.sa_handler = &send_signal;
	sa.sa_flags = 0;
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		ft_putstr("Error - Problem receiving signal");
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		ft_putstr("Error - Problem receiving signal");
}

void	send_bit(int pid, char bit)
{
	int				bit_i;
	unsigned char	temp;

	bit_i = 8;
	temp = (unsigned char)bit;
	while (bit_i--)
	{
		g_send_bit = 0;
		temp = (bit >> bit_i);
		if (temp % 2 == 0)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		while (!g_send_bit)
			;
	}
}

void	send_message(int pid, char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		send_bit(pid, str[i]);
		sleep(1);
		ft_putstr("Signal Received from Server\n");
	}
	send_bit(pid, '\0');
}

int	main(int ac, char **av)
{
	int	pid;

	ft_check(ac, av);
	pid = ft_atoi(av[1]);
	if (pid <= 0)
	{
		ft_putstr("Invalid PID\n");
		exit(EXIT_FAILURE);
	}
	sig_handler();
	if (av[2][0] == '\0')
		send_message(pid, "\0");
	else
		send_message(pid, av[2]);
	send_message(pid, "\n");
	return (0);
}
