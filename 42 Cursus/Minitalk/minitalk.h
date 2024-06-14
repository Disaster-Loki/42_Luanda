/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <sde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 17:04:51 by sde-carv          #+#    #+#             */
/*   Updated: 2024/06/14 12:08:04 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>
# include "./ft_printf/ft_printf.h"

int		ft_isdigit(int c);
int		ft_atoi(char *ptr);
void	ft_check(int av, char **arg);

#endif
