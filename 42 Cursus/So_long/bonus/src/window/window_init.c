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

void	get_init(t_game *game, char **args)
{
	game->flag = 0;
	game->move = 0;
	game->cf = 0;
	game->count = 0;
	game->frame = 0;
	game->c_tibles = 0;
	game->mlx = mlx_init();
	game->g_name = "SO LONG";
	game->map = get_map(args[1]);
	game->t_tibles = total_collectable(game->map);
	game->pos.y = 30 + ft_len_line(game->map) * 32;
	game->pos.x = (int)ft_strlen(*(game->map)) * 32;
}

void	print_t_tibles(t_game *g)
{
	char	*str;
	char	*t_tibles;
	char	*f_str;
	int		len;

	str = "Collectables : ";
	t_tibles = ft_itoa(total_collectable(g->map));
	len = ft_strlen(str) + ft_strlen(t_tibles) + 1;
	f_str = (char *)malloc(sizeof(char) * len);
	if (!f_str)
		return ;
	ft_strlcpy(f_str, str, len);
	ft_strlcat(f_str, t_tibles, len);
	mlx_put_image_to_window(g->mlx, g->win, g->img.path, 90 + 25 + 32, 0);
	mlx_put_image_to_window(g->mlx, g->win, g->img.path, 90 + 55 + 32, 0);
	mlx_string_put(g->mlx, g->win, 90, 17, 0xFFFFFF, f_str);
	free(t_tibles);
	free(f_str);
}

void	print_steps(t_game *game)
{
	char	*str;
	char	*steps;
	char	*f_str;
	int		len;

	str = "Steps : ";
	steps = ft_itoa(game->count);
	len = ft_strlen(str) + ft_strlen(steps) + 1;
	f_str = (char *)malloc(sizeof(char) * len);
	if (!f_str)
		return ;
	ft_strlcpy(f_str, str, len);
	ft_strlcat(f_str, steps, len);
	mlx_put_image_to_window(game->mlx, game->win, game->img.path, 25 + 32, 0);
	mlx_put_image_to_window(game->mlx, game->win, game->img.path, 55 + 32, 0);
	mlx_string_put(game->mlx, game->win, 10, 17, 0xFFFFFF, f_str);
	free(steps);
	free(f_str);
}

void	window_init(char **args)
{
	t_game	game;

	get_init(&game, args);
	get_count_steps(&game);
	get_img_path(game.mlx, &game.img, 0, 0);
	game.win = mlx_new_window(game.mlx, game.pos.x, game.pos.y, game.g_name);
	mlx_hook(game.win, 02, 1L << 0, keypress, &game);
	mlx_hook(game.win, 17, 0, close_game, &game);
	print_map_window(&game);
	mlx_loop_hook(game.mlx, manipulate_enemies, &game);
	mlx_loop(game.mlx);
}
