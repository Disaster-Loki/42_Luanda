/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 13:26:47 by sde-carv          #+#    #+#             */
/*   Updated: 2024/08/25 13:26:49 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

int	keypress(int key, t_windows *win)
{
	t_point	begin;

	begin = begin_position(win->map, 'P');
	if (key == 'w')
	{	
		win->map[begin.x][begin.y] = '0';
		win->map[begin.x - 1][begin.y] = 'P';
		print_map_window(win->mlx, win->win, win->map);
	}
	if (key == 's')
	{	
		win->map[begin.x][begin.y] = '0';
		win->map[begin.x + 1][begin.y] = 'P';
		print_map_window(win->mlx, win->win, win->map);
	}
	if (key == 'd')
	{	
		win->map[begin.x][begin.y] = '0';
		win->map[begin.x][begin.y + 1] = 'P';
		print_map_window(win->mlx, win->win, win->map);
	}
	if (key == 'a')
	{	
		win->map[begin.x][begin.y] = '0';
		win->map[begin.x][begin.y - 1] = 'P';
		print_map_window(win->mlx, win->win, win->map);
	}
	return (1);
}
