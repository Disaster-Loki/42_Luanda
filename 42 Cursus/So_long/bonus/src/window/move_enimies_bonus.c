/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_enimies.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 08:59:47 by sde-carv          #+#    #+#             */
/*   Updated: 2024/09/03 08:59:50 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long_bonus.h"

void	move_enemy_tibles(t_game *game, int line, int col, int new_x)
{
	if (game->map[line][new_x] == 'C')
	{
		game->v_tible = 0;
		if (game->move_tibles[line][col] == 1)
		{
			game->map[line][col] = 'C';
			game->move_tibles[line][col] = 0;
		}
		else
			game->map[line][col] = '0';
		game->map[line][new_x] = 'I';
		game->move_tibles[line][new_x] = 1;
	}
}

void	move_enemy_to_empty(t_game *game, int line, int col, int new_x)
{
	if (game->move_tibles[line][col] == 1)
	{
		game->map[line][col] = 'C';
		game->move_tibles[line][col] = 0;
	}
	else
		game->map[line][col] = '0';
	game->map[line][new_x] = 'I';
}

void	handle_enemy_collision(t_game *game, int line, int col, int new_x)
{
	if (game->map[line][new_x] == 'C')
		move_enemy_tibles(game, line, col, new_x);
	if (game->map[line][new_x] == 'P')
		game_over(game, 'P');
}

int	is_valid_move(int new_x, int t_col, char c)
{
	return (new_x >= 0 && new_x < t_col && (c == '0' || c == 'C' || c == 'P'));
}
