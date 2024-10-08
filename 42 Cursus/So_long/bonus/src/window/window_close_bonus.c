/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_close.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 09:09:16 by sde-carv          #+#    #+#             */
/*   Updated: 2024/08/26 09:09:18 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long_bonus.h"

void	close_img(void *mlx, t_img *img)
{
	int	i;

	i = -1;
	while (++i < 8)
	{
		if (img->player[i])
			mlx_destroy_image(mlx, img->player[i]);
	}
	if (img->enemy[0])
		mlx_destroy_image(mlx, img->enemy[0]);
	if (img->enemy[1])
		mlx_destroy_image(mlx, img->enemy[1]);
	if (img->enemy[2])
		mlx_destroy_image(mlx, img->enemy[2]);
	if (img->enemy[3])
		mlx_destroy_image(mlx, img->enemy[3]);
	if (img->coin)
		mlx_destroy_image(mlx, img->coin);
	if (img->exit)
		mlx_destroy_image(mlx, img->exit);
	if (img->path)
		mlx_destroy_image(mlx, img->path);
	if (img->wall)
		mlx_destroy_image(mlx, img->wall);
}

int	window_close(t_game *game)
{
	int	rows;

	rows = ft_len_line(game->map);
	free_map(game->map);
	free_matrix(game->move_tibles, rows);
	mlx_clear_window(game->mlx, game->win);
	close_img(game->mlx, &game->img);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	return (0);
}

int	window_stop(t_game *game)
{
	int	rows;

	rows = ft_len_line(game->map);
	free_map(game->map);
	free_matrix(game->move_tibles, rows);
	close_img(game->mlx, &game->img);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	return (0);
}

int	close_game(t_game *game)
{
	if (!window_close(game))
		exit(0);
	return (0);
}

void	game_over(t_game *game, char c)
{
	if (c == 'I' || c == 'P')
	{
		ft_putstr_fd("Game Over !!\n", 1);
		close_game(game);
	}
}
