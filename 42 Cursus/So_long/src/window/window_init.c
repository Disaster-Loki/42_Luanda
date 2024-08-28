/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 10:32:26 by sde-carv          #+#    #+#             */
/*   Updated: 2024/08/25 10:32:29 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

void	get_img_path(char *mlx, t_img *img)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	img->wall = mlx_xpm_file_to_image(mlx, "./assets/wall.xpm", &x, &y);
	img->player[0] = mlx_xpm_file_to_image(mlx, "./assets/player.xpm", &x, &y);
	img->player[1] = mlx_xpm_file_to_image(mlx, "./assets/player2.xpm", &x, &y);
	img->player[2] = mlx_xpm_file_to_image(mlx, "./assets/player3.xpm", &x, &y);
	img->player[3] = mlx_xpm_file_to_image(mlx, "./assets/player4.xpm", &x, &y);
	img->path = mlx_xpm_file_to_image(mlx, "./assets/path.xpm", &x, &y);
	img->coin = mlx_xpm_file_to_image(mlx, "./assets/coin.xpm", &x, &y);
	img->exit = mlx_xpm_file_to_image(mlx, "./assets/exit.xpm", &x, &y);
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
}

void	print_map_window(t_game *game)
{
	int		i;
	int		j;

	i = -1;
	game->img.wid = 0;
	game->img.hei = 0;
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

void	get_init(t_game *game, char **args)
{
	game->flag = 0;
	game->count = 0;
	game->c_tibles = 0;
	game->mlx = mlx_init();
	game->g_name = "SO LONG";
	game->map = get_map(args[1]);
	game->t_tibles = total_collectable(game->map);
	game->pos.y = ft_len_line(game->map) * 32;
	game->pos.x = (int)ft_strlen(*(game->map)) * 32;
}

void	window_init(char **args)
{
	t_game	game;

	get_init(&game, args);
	get_count_steps(&game);
	get_img_path(game.mlx, &game.img);
	game.win = mlx_new_window(game.mlx, game.pos.x, game.pos.y, game.g_name);
	mlx_hook(game.win, 02, 1L << 0, keypress, &game);
	mlx_hook(game.win, 17, 0, close_game, &game);
	print_map_window(&game);
	mlx_loop(game.mlx);
}
