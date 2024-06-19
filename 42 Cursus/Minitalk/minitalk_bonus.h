/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <sde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 17:04:51 by sde-carv          #+#    #+#             */
/*   Updated: 2024/06/17 10:17:55 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>

void	ft_putnbr(int n);
int		ft_isdigit(int c);
int		ft_atoi(char *ptr);
void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_check(int av, char **arg);

#endif
