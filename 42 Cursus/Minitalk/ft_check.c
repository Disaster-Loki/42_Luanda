/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <sde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 11:30:04 by sde-carv          #+#    #+#             */
/*   Updated: 2024/06/14 12:05:23 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_check(int av, char **arg)
{
	int	i;

	if (av != 3)
		ft_printf("Error - Usage: ./cliente [server_pid] [message]");
	i = 0;
	while (arg[1][i])
	{
		if (ft_isdigit(arg[1][i]) == 0)
			ft_printf("Error - Invalid PID");
		++i;
	}
	if (arg[2] == 0)
		ft_printf("Error - Invalid message");
}