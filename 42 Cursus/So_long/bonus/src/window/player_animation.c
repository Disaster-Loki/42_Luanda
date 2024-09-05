/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_animation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 17:13:32 by sde-carv          #+#    #+#             */
/*   Updated: 2024/09/05 17:13:34 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long_bonus.h"

void	get_player_animation(t_game *game, int x, int y)
{
	if (x == -1 && y == 0)
		game->flag = 4;
	if (x == 1 && y == 0)
		game->flag = 5;
	if (x == 0 && y == 1)
		game->flag = 6;
	if (x == 0 && y == -1)
		game->flag = 7;
	game->c_tibles++;
}

void	print_image_player(t_game *g, int w, int h)
{
	if (g->flag == 0)
		mlx_put_image_to_window(g->mlx, g->win, g->img.player[4], w, h);
	else if (g->flag == 1)
		mlx_put_image_to_window(g->mlx, g->win, g->img.player[5], w, h);
	else if (g->flag == 2)
		mlx_put_image_to_window(g->mlx, g->win, g->img.player[6], w, h);
	else if (g->flag == 3)
		mlx_put_image_to_window(g->mlx, g->win, g->img.player[7], w, h);
	else if (g->flag == 4)
		mlx_put_image_to_window(g->mlx, g->win, g->img.player[1], w, h);
	else if (g->flag == 5)
		mlx_put_image_to_window(g->mlx, g->win, g->img.player[2], w, h);
	else if (g->flag == 6)
		mlx_put_image_to_window(g->mlx, g->win, g->img.player[0], w, h);
	else if (g->flag == 7)
		mlx_put_image_to_window(g->mlx, g->win, g->img.player[3], w, h);
}
