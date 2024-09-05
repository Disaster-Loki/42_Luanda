/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 12:16:30 by sde-carv          #+#    #+#             */
/*   Updated: 2024/08/30 12:16:32 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long_bonus.h"

void	get_img_path_enemy(char *mlx, t_img *img, int x, int y)
{
	img->enemy[0] = mlx_xpm_file_to_image(mlx, "./assets/red1.xpm", &x, &y);
	img->enemy[1] = mlx_xpm_file_to_image(mlx, "./assets/red22.xpm", &x, &y);
	img->enemy[2] = mlx_xpm_file_to_image(mlx, "./assets/red3.xpm", &x, &y);
	img->enemy[3] = mlx_xpm_file_to_image(mlx, "./assets/red4.xpm", &x, &y);
}

void	get_img_path_player(char *mlx, t_img *img, int x, int y)
{
	img->player[0] = mlx_xpm_file_to_image(mlx, "./assets/player.xpm", &x, &y);
	img->player[1] = mlx_xpm_file_to_image(mlx, "./assets/player2.xpm", &x, &y);
	img->player[2] = mlx_xpm_file_to_image(mlx, "./assets/player3.xpm", &x, &y);
	img->player[3] = mlx_xpm_file_to_image(mlx, "./assets/player4.xpm", &x, &y);
}

void	get_img_path(t_game *game, char *mlx, t_img *img)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	img->wall = mlx_xpm_file_to_image(mlx, "./assets/wall.xpm", &x, &y);
	img->path = mlx_xpm_file_to_image(mlx, "./assets/path.xpm", &x, &y);
	img->coin = mlx_xpm_file_to_image(mlx, "./assets/coin.xpm", &x, &y);
	img->exit = mlx_xpm_file_to_image(mlx, "./assets/exit.xpm", &x, &y);
	get_img_path_player(mlx, img, x, y);
	get_img_path_enemy(mlx, img, x, y);
	valid_img_path(game, img);
}

void	print_image(t_game *g, char c, int w, int h)
{
	if (c == '1')
		mlx_put_image_to_window(g->mlx, g->win, g->img.wall, w, h);
	if (c == '0')
		mlx_put_image_to_window(g->mlx, g->win, g->img.path, w, h);
	if (c == 'E')
		mlx_put_image_to_window(g->mlx, g->win, g->img.exit, w, h);
	if (c == 'P')
	{
		if (g->flag == 0)
			mlx_put_image_to_window(g->mlx, g->win, g->img.player[0], w, h);
		else if (g->flag == 1)
			mlx_put_image_to_window(g->mlx, g->win, g->img.player[1], w, h);
		else if (g->flag == 2)
			mlx_put_image_to_window(g->mlx, g->win, g->img.player[2], w, h);
		else if (g->flag == 3)
			mlx_put_image_to_window(g->mlx, g->win, g->img.player[3], w, h);
	}
	if (c == 'C')
		mlx_put_image_to_window(g->mlx, g->win, g->img.coin, w, h);
	if (c == 'I')
		mlx_put_image_to_window(g->mlx, g->win, g->img.enemy[g->frame], w, h);
}

void	print_map_window(t_game *game)
{
	int		i;
	int		j;

	i = -1;
	game->img.wid = 0;
	game->img.hei = 30;
	print_steps(game);
	print_t_tibles(game);
	while (game->map[++i])
	{
		j = -1;
		game->img.wid = 0;
		while (game->map[i][++j])
		{	
			print_image(game, game->map[i][j], game->img.wid, game->img.hei);
			game->img.wid += 32;
		}
		game->img.hei += 32;
	}
}
