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

#include "../../inc/so_long_bonus.h"

void	get_count_steps(t_game *game)
{
	ft_putstr_fd("Steps: ", 1);
	ft_putnbr_fd(game->count, 1);
	ft_putchar_fd('\n', 1);
}

void	get_count_exit(t_game *game)
{
	game->count++;
	get_count_steps(game);
	print_steps(game);
	ft_putstr_fd("Winner !!\n", 1);
	close_game(game);
}

void	get_alter_position(t_game *game, t_point begin, int x, int y)
{
	char	move;

	game->v_tible = 1;
	move = game->map[begin.x + x][begin.y + y];
	game_over(game, move);
	if (move == 'C')
		game->c_tibles++;
	if (move != '1')
	{
		if (move == 'E')
		{
			if (game->t_tibles == game->c_tibles)
				get_count_exit(game);
			else
				return ;
		}
		else
		{
			game->map[begin.x][begin.y] = '0';
			game->map[begin.x + x][begin.y + y] = 'P';
		}
		game->count++;
		get_count_steps(game);
		print_map_window(game);
	}
}

int	keypress(int key, t_game *game)
{
	game->pos = begin_position(game->map, 'P');
	if (key == 'w' || key == 65362)
	{
		game->flag = 1;
		get_alter_position(game, game->pos, -1, 0);
	}
	if (key == 's' || key == 65364)
	{
		game->flag = 2;
		get_alter_position(game, game->pos, 1, 0);
	}
	if (key == 'd' || key == 65363)
	{
		game->flag = 0;
		get_alter_position(game, game->pos, 0, 1);
	}
	if (key == 'a' || key == 65361)
	{
		game->flag = 3;
		get_alter_position(game, game->pos, 0, -1);
	}
	if (key == ESC)
		close_game(game);
	return (1);
}
