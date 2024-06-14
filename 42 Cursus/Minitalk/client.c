/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <sde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 17:03:59 by sde-carv          #+#    #+#             */
/*   Updated: 2024/06/14 12:32:54 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	get_bit;

void	send_signal(int signal)
{
	if (signal == SIGUSR1)
		get_bit = 1;
}

void	sig_handler(void)
{
	struct sigaction	sa;
	
	sa.sa_handler = &send_signal;
	sa.sa_flags = 0;
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		ft_printf("Error - Problem receiving signal");
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		ft_printf("Error - Problem receiving signal");
}

void	send_bit(int pid, char bit)
{
	int				bit_i;
	unsigned char	temp;
	
	bit_i = 0;
	temp = (unsigned char) bit;
	while(bit_i--)
	{
		get_bit = 0;
		temp = (bit >> bit_i);
		if (temp % 2 == 0)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		while (!get_bit);
	}
}

void	send_message(int pid, char *str)
{
	int	i;
	
	i = -1;
	while (str[++i])
		send_bit(pid, str[i]);
}

int	main(int av, char **args)
{
	int	pid;

	ft_check(av, args);
	pid = ft_atoi(args[1]);
	if (pid <= 0)
	{
		ft_printf("Invalid PID\n");
		exit (EXIT_FAILURE);
	}
	sig_handler();
	if (args[2][0] == '\0')
		send_message(pid, "\0");
	send_message(pid, args[2]);
	send_message(pid, "\n");
	return (0);
}