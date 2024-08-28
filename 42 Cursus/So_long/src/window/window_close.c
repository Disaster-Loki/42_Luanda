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

#include "../../inc/so_long.h"

void	close_img(void *mlx, t_img *img)
{
	mlx_destroy_image(mlx, img->player[0]);
	mlx_destroy_image(mlx, img->player[1]);
	mlx_destroy_image(mlx, img->player[2]);
	mlx_destroy_image(mlx, img->player[3]);
	mlx_destroy_image(mlx, img->coin);
	mlx_destroy_image(mlx, img->exit);
	mlx_destroy_image(mlx, img->path);
	mlx_destroy_image(mlx, img->wall);
}

int	window_close(t_game *game)
{
	ft_free(game->map);
	mlx_clear_window(game->mlx, game->win);
	close_img(game->mlx, &game->img);
	mlx_destroy_window(game->mlx, game->win);
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
