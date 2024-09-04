/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windows_enemies.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 12:01:38 by sde-carv          #+#    #+#             */
/*   Updated: 2024/08/30 12:01:40 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long_bonus.h"

void	move_enemy(t_game *game, int line)
{
	int	col;
	int	t_col;
	int	new_x;

	col = 0;
	t_col = (int)ft_strlen(game->map[line]);
	while (col < t_col)
	{
		if (game->map[line][col] == 'I')
		{
			new_x = col + game->move;
			if (is_valid_move(new_x, t_col, game->map[line][new_x]))
			{
				if (game->map[line][new_x] == '0')
					move_enemy_to_empty(game, line, col, new_x);
				else
					handle_enemy_collision(game, line, col, new_x);
				col = new_x;
			}
		}
		col++;
	}
}

void	get_alter_direction(t_game *game)
{
	game->t_move++;
	if (game->t_move == 6)
	{
		game->move = -game->move;
		game->t_move = 0;
	}
}

void	get_move_enimy(t_game *game)
{
	int	i;
	int	line;

	i = -1;
	line = ft_len_line(game->map);
	while (++i < line)
		move_enemy(game, i);
}

int	manipulate_enemies(t_game *game)
{
	game->frame_count++;
	if (game->frame_count >= 100)
	{
		game->frame_count = 0;
		game->frame = (game->frame + 1) % 4;
		get_move_enimy(game);
		get_alter_direction(game);
		print_map_window(game);
	}
	usleep(10000);
	return (0);
}
